#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <sstream>
#include <iterator>

class PrefixPostfix
{
public:
    PrefixPostfix();
    PrefixPostfix(std::string);
    ~PrefixPostfix();
    std::string postfix();
    std::string prefix();
    void setEquation(std::string);
    std::string getEquation() const { return equation; };
    void clear();

private:
    std::string equation;
    std::ostringstream postoutput, preoutput;
    const std::string postfixoperator = "*/+-(";
    const std::string prefixoperator = "*/+-)";
    const unsigned short operatorsvalue[5] = {2, 2, 1, 1, 0};
    std::vector<char> operatorvector, postfixvector, prefixvector;
    std::vector<char>::iterator itr;

protected:
};