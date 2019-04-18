#include "Hangman.h"

std::string hide_word(std::string mystery_word)
{
    unsigned short measure = 0;
    measure = mystery_word.length();
    for (unsigned short index = 0; index < measure; index++)
    {
        if (mystery_word[index] != ' ')
        {
            mystery_word[index] = '-';
        }
    }
    return mystery_word;
}

std::string mysteryCapital(std::string mystery_word)
{
    unsigned short measure = 0;
    measure = mystery_word.length();
    for (unsigned short index; index < measure; index++)
    {
        mystery_word[index] = toupper(mystery_word[index]);
    }
    return mystery_word;
}

bool isUserInputValid(std::string userInput)
{
    if (userInput.length() > 1 || userInput.length() == 0 || userInput == " ")
        return false;
    return true;
}
