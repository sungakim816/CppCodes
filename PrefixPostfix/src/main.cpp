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
	PrefixPostfix p;
	std::ifstream inputFile;
	inputFile.open("input.txt");
	std::string txtInput;
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			std::getline(inputFile, txtInput);
			p.setEquation(txtInput);
			std::cout << "INFIX: " << p.getEquation() << std::endl;
			std::cout << "PREFIX: " << p.prefix() << " ";
			std::cout << "POSTFIX: " << p.postfix() << std::endl
					  << std::endl;
		}
	}
	inputFile.close();
	return 0;
}