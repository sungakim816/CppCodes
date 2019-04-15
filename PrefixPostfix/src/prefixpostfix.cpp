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
        else if (equation[idx] == '(')
        {
            // if equation[idx] is a '(' push it to the operator stack;
            operatorvector.push_back(equation[idx]);
        }
        else if (postfixoperator.find(equation[idx]) != std::string::npos && operatorvector.empty())
        {
            // if equation[idx] is an operator and operatorvector is empty push it to the vector;
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
    std::copy(postfixvector.begin(), postfixvector.end(), std::ostream_iterator<char>(postoutput, ""));
    return postoutput.str();
}

std::string PrefixPostfix::prefix()
{
    return "";
}

void PrefixPostfix::clear()
{
    postfixvector.clear();
    operatorvector.clear();
    postoutput.str(std::string());
    postoutput.clear();
    preoutput.str(std::string());
    preoutput.clear();
    equation = "";
}