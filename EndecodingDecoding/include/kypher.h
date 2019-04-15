#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class Kypher
{
public:
    Kypher();
    ~Kypher();
    std::string encode(std::string message);
    std::string decode(std::string message);

protected:
private:
    std::string alphabet = "ABCDEFGHIKJLMNOPQRSTUVWXYZabcdefghikjlmnopqrstuvwxyz";
    // "EsAVutBGheLWDUrxqjlicIdgnHvQFZOpkKCmfwMJNbyXRTozYSaP";
    std::string alphabetShuffle = "EsAVutBGheLWDUrxqjlicIdgnHvQFZOpkKCmfwMJNbyXRTozYSaP";
};
