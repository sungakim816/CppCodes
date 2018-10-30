#include <iostream>
#include <string>
#include <vector>
#include <algorithm>//do not erase no more
#include <ctime>
#include <cctype>
#include <cstring>
#include <sstream>
#include "Hangman.h"
using namespace std;

int main(){
string mystery_word = "", hidden_mystery_word = "", mystery_word_all_caps = "", user_input = "", previous_inputs = "";
string alphabethLetters = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z", message = "";
short lifePoints = 5;
cout<<"Enter The Mystery Word: ";
getline(cin, mystery_word);

hidden_mystery_word = hide_word(mystery_word);

mystery_word_all_caps= mysteryCapital(mystery_word); // ALL CAPS MYSTERY WORD
system("cls");

for(;;){//main loop
   cout<<endl<<hidden_mystery_word<<endl;
   cout<<message;
   cout<<endl<<alphabethLetters<<endl;
   cout<<endl<<"Previous Input/s: "<<previous_inputs<<endl<<endl;
   cout<<"Enter Your Guess: ";
   getline(cin, user_input);

   if (isUserInputValid(user_input)){
   user_input[0] = toupper(user_input[0]); // CHANGE TO UPPER CASE USER GUESS..

    if (previous_inputs.find(user_input) == string::npos && mystery_word_all_caps.find(user_input) != string::npos){
        previous_inputs += user_input;
        alphabethLetters.replace(alphabethLetters.find(user_input), 1, "-");
    for (unsigned int index = 0; index < mystery_word.length(); index++){

        if (user_input[0] == mystery_word_all_caps[index]){ // CHECKS THE USER INPUT

            hidden_mystery_word.replace(index, 1, mystery_word.substr(index, 1)); // REPLACE IF THE USER GUESS EXITS IN THE MYSTERY WORD
        }
    }
    message = "";
    if (mystery_word == hidden_mystery_word){
		cout<<"You Solved the Mystery Word which is "<< mystery_word << endl;
        cout<<endl<<"   Congratulations....."<<endl<<"    Thanks For Playing. See You Next Time"<<endl;
        break;
    }
    }else if (previous_inputs.find(user_input) != string::npos){
        stringstream stream;
        stream << "\n"<< user_input << " is already been entered. Pls try Again.\n" << lifePoints << " life/lives remaining.\n";
        message = stream.str();
    }else if (previous_inputs.find(user_input) == string::npos && mystery_word_all_caps.find(user_input) == string::npos){
        previous_inputs += user_input;
        alphabethLetters.replace(alphabethLetters.find(user_input), 1, "-");
        stringstream stream;
        stream << "\n"<< user_input << " is not on the mystery word\n" << --lifePoints << " life/lives remaining.\n";
        message = stream.str();
        if (lifePoints == 0){
            cout<<endl<<"You have Zero Life Points "<<endl<<endl<<"The Mystery Word is: "<<mystery_word << "\n";
            break;
        }
    }
   }else {
        message = "\nInvalid Input, Please Try Again";
    }
   system("cls");
}
system("pause");
return 0;

}

