#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <sstream>
#include <iterator>
#include <fstream>
#include "prefixpostfix.h"

int main(int argc, char *argv[])
{
	// std::ifstream inputFile;
	// inputFile.open("input.txt");
	// std::string txtInput;
	// if (inputFile.is_open())
	// {
	// 	std::cout << "\t\tInfix "
	// 			  << "Postfix\t\t" << std::endl;
	// 	while (!inputFile.eof())
	// 	{
	// 		std::getline(inputFile, txtInput);
	// 		std::cout << "\t\t" << txtInput << "\t\t" << postfix(txtInput) << std::endl;
	// 	}
	// }
	// inputFile.close();
	std::string userInput = "A+b*c";
	PrefixPostfix p;
	p.setEquation(userInput);
	std::cout << p.postfix() << std::endl;
	std::cout << p.postfix() << std::endl;
	return 0;
}