#include "prefixpostfix.h"

PrefixPostfix::PrefixPostfix()
{
}

PrefixPostfix::PrefixPostfix(std::string s)
{
    this->equation = s;
}

PrefixPostfix::~PrefixPostfix()
{
}

void PrefixPostfix::setEquation(std::string s)
{
    this->clear();
    this->equation = s;
}

std::string PrefixPostfix::postfix()
{
    if (postoutput.str().length() > 0)
    {
        return postoutput.str();
    }
    for (unsigned int idx = 0; idx < equation.length(); idx++)
    {
        if (std::isalnum(equation[idx]))
        {
            //if equation[idx] is an alpha-numeric, push it to the postfixvector
            postfixvector.push_back(equation[idx]);
        }
        else if ((equation[idx] == '(') || (postfixoperator.find(equation[idx]) != std::string::npos && operatorvector.empty()))
        {
            // if equation[idx] is a '(' push it to the operator stack;
            operatorvector.push_back(equation[idx]);
        }
        else if (equation[idx] == ')')
        {
            // if equation[idx] is ')' push the content of operatorvector until '(' is found;
            while (operatorvector.back() != '(')
            {
                postfixvector.push_back(operatorvector.back());
                operatorvector.pop_back();
            }
            operatorvector.pop_back();
        }
        else if (postfixoperator.find(equation[idx]) != std::string::npos)
        {
            unsigned int oprvalue = operatorsvalue[postfixoperator.find(equation[idx])];
            while (operatorsvalue[postfixoperator.find(operatorvector.back())] >= oprvalue)
            {
                postfixvector.push_back(operatorvector.back());
                operatorvector.pop_back();
            }
            operatorvector.push_back(equation[idx]);
        }
    }
    for (itr = operatorvector.end() - 1; itr >= operatorvector.begin(); itr--)
    {
        postfixvector.push_back(*itr);
    }
    operatorvector.clear();
    std::copy(postfixvector.begin(), postfixvector.end(), std::ostream_iterator<char>(postoutput, ""));
    return postoutput.str();
}

std::string PrefixPostfix::prefix()
{
    if (preoutput.str().length() > 0)
    {
        return preoutput.str();
    }
    for (int idx = equation.length() - 1; idx >= 0; idx--)
    {
        if (std::isalnum(equation[idx]))
        {
            prefixvector.insert(prefixvector.begin(), equation[idx]);
        }
        else if ((equation[idx] == ')') || (prefixoperator.find(equation[idx]) != std::string::npos && operatorvector.empty()))
        {
            operatorvector.push_back(equation[idx]);
        }
        else if (equation[idx] == '(')
        {
            while (operatorvector.back() != ')')
            {
                prefixvector.insert(prefixvector.begin(), operatorvector.back());
                operatorvector.pop_back();
            }
            operatorvector.pop_back();
        }
        else if (prefixoperator.find(equation[idx]) != std::string::npos)
        {
            unsigned int oprvalue = operatorsvalue[prefixoperator.find(equation[idx])];
            while (operatorsvalue[prefixoperator.find(operatorvector.back())] >= oprvalue)
            {
                prefixvector.insert(prefixvector.begin(), operatorvector.back());
                operatorvector.pop_back();
            }
            operatorvector.push_back(equation[idx]);
        }
    }
    for (itr = operatorvector.end() - 1; itr >= operatorvector.begin(); itr--)
    {
        prefixvector.insert(prefixvector.begin(), *itr);
    }
    operatorvector.clear();
    std::copy(prefixvector.begin(), prefixvector.end(), std::ostream_iterator<char>(preoutput, ""));
    return preoutput.str();
}

void PrefixPostfix::clear()
{
    postfixvector.clear();
    prefixvector.clear();
    operatorvector.clear();
    postoutput.str(std::string());
    postoutput.clear();
    preoutput.str(std::string());
    preoutput.clear();
    equation = "";
}