#include "Hangman.h"

std::string hide_word(std::string mystery_word){
unsigned int index = 0, measure = 0;
measure = mystery_word.length();
for(index = 0; index < measure; index++){
        if (mystery_word[index] != ' '){

            mystery_word[index] = '-';
        }
}
return mystery_word;
}

std::string mysteryCapital(std::string mystery_word){
unsigned int index = 0, measure = 0;
measure = mystery_word.length();
for(; index < measure; index++){
    mystery_word[index] = toupper(mystery_word[index]);
}
return mystery_word;
}
