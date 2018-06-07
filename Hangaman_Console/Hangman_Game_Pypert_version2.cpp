#include <iostream>
#include <string>
#include <vector>
#include <algorithm>//do not erase no more
#include <ctime>
#include <cctype>
#include <cstring>
#include "Hangman.h"
using namespace std;

int main(){
string mystery_word0 = "", mystery_word1 = "", mystery_word2 = "", mystery_word1_copy = "", user_input = "", previous_inputs = "";
int lifePoints = 5;
cout<<"Enter The Mystery Word: ";
getline(cin, mystery_word0);

mystery_word1 = hide_word(mystery_word0);

mystery_word2 = mysteryCapital(mystery_word0); // ALL CAPS MYSTERY WORD
system("cls");

for(;;){//main loop
   cout<<endl<<mystery_word1<<endl;
   cout<<endl<<"Previous Input/s: "<<previous_inputs<<endl<<endl;
   cout<<"Enter Your Guess: ";
   cin>>user_input;

   if (user_input.length() == 1){
   user_input[0] = toupper(user_input[0]); // CHANGE TO UPPER CASE USER GUESS..

    if (previous_inputs.find(user_input) == string::npos && mystery_word2.find(user_input) != string::npos){
        previous_inputs += user_input;
    for (unsigned int index = 0; index < mystery_word0.length(); index++){

        if (user_input[0] == mystery_word2[index]){ // CHECKS THE USER INPUT

            mystery_word1.replace(index, 1, mystery_word0.substr(index, 1)); // REPLACE IF THE USER GUESS EXITS IN THE MYSTERY  WORD
        }
    }
    if (mystery_word0 == mystery_word1){
		cout<<"You Solved the Mystery Word which is "<< mystery_word0 << endl;
        cout<<endl<<"   Congratulations....."<<endl<<"    Thanks For Playing. See You Next Time"<<endl;
        break;
    }
    }else if (previous_inputs.find(user_input) != string::npos){

        cout<<endl<<user_input<<" is already been entered. Pls Try Again."<<endl;
        cout<<lifePoints<<" life/lives remaining"<<endl;
    }else if (previous_inputs.find(user_input) == string::npos && mystery_word2.find(user_input) == string::npos){
        previous_inputs += user_input;
        cout<<endl<<user_input<<" is not on the mystery word "<<endl;
        cout<<--lifePoints<<" life/lives remaining"<<endl;
        if (lifePoints == 0){
            cout<<endl<<"You have Zero Life Points "<<endl<<endl<<"The Mystery Word is: "<<mystery_word0;
            break;
        }
    }
   }else cout<<endl<<"Invalid Input, One Character At a Time"<<endl;
}
system("pause");
return 0;

}

