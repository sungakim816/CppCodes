#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const string alphabetCapital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string codedVersion1 = "#AKRTQIWEVHFYGDZXLPSOUBMNC";//J
string decode(string message);
string encode(string message);
bool welcome_(){//function to welcome the user
string w_option = "";
bool w_dec_or_en = false;

cout<<"ENCODE/HIDE or DECODE a Message? "<<endl<<endl;

for(;;){
    cout<<"1 to ENCODE, 2 to DECODE: ";
    getline(cin, w_option);

    if (w_option == "1"){

            w_dec_or_en = true;
            break;

    }else if (w_option == "2"){
    w_dec_or_en = false;
    break;
        }else if (w_option.length() == 0){
        system("cls");
        }else system("cls");

}
return w_dec_or_en;
}

int main(){//main function
bool dec_or_en = false;
string message = "", option = "";
do{
dec_or_en = welcome_();
cout<<endl<<"Enter your Message: ";
getline(cin, message);

if (dec_or_en) {

        message = encode(message);//function to replace each character
        cout<<endl<<endl<<"The Encoded Message is: ";
            }
else if(!dec_or_en)
{
    message = decode(message);//function to decode the message
    cout<<endl<<endl<<"The Decoded Message is: ";
    }

cout<<message<<endl<<endl<<endl;

cout<<"Would You Like To Encode/Decode Another Message (y/n): ";
getline(cin,option);
cout<<endl<<endl;
}while((option != "n" || option != "N") && (option == "y" || option == "Y"));
return 0;
}


//functions
string encode(string message){//encoding message
int findCapital = 0;
for(int i = 0; i < message.size(); i++){// turn each character into capital letters.

message[i] = toupper(message[i]);

}

for(int i = 0; i < message.size(); i++){
findCapital = alphabetCapital.find(message.substr(i, 1));

    if(findCapital != string::npos){
       message.replace(i, 1, codedVersion1.substr(findCapital, 1));

    } else {
    //do nothing
    }
}
return message;
}


string decode(string message){// for decoding message
int findCoded = 0;
for(int i = 0; i < message.size(); i++){// turn each characters into capital letters.

message[i] = toupper(message[i]);

}

for(int i = 0; i < message.size(); i++){//decoding message
findCoded = codedVersion1.find(message.substr(i, 1));

    if(findCoded != string::npos){
       message.replace(i, 1, alphabetCapital.substr(findCoded, 1));

    } else {
    //do nothing
    }
}
return message;
}
