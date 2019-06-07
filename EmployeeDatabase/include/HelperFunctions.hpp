#ifndef HelperFunctions_hpp
#define HelperFunctions_hpp

#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::getline;
using std::string;


namespace pypert {
    int GetValidSignedIntegerInput();
    string StringToTitle(string s);
    float GetValidFloatInput();
    char GetValidCharInput();
}



#endif /* HelperFunctions_hpp */