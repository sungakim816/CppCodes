#include "kypher.h"

Kypher::Kypher()
{
}

Kypher::~Kypher()
{
}

std::string Kypher::encode(std::string message)
{
    unsigned int count = 0;
    while (count < message.length())
    {
        for (unsigned int idx = 0; idx < message.length(); idx++)
        {
            if (alphabetShuffle.find(message[idx]) != std::string::npos)
            {
                message.replace(idx, 1, alphabetShuffle.substr(alphabet.find(message[idx]), 1));
            }
        }
        count++;
    }

    return message;
}

std::string Kypher::decode(std::string message)
{
    unsigned int count = 0;
    while (count < message.length())
    {
        for (unsigned int idx = 0; idx < message.length(); idx++)
        {
            if (alphabet.find(message[idx]) != std::string::npos)
            {
                message.replace(idx, 1, alphabet.substr(alphabetShuffle.find(message[idx]), 1));
            }
        }
        count++;
    }

    return message;
}
