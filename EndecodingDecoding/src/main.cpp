#include <iostream>
#include <string>
#include "kypher.h"

int main(int argc, char *argv[])
{
	Kypher messageEncDec;
	std::string inputString;
	std::string outputString;
	std::cout << "Message: ";
	std::getline(std::cin, inputString);
	outputString = messageEncDec.encode(inputString);
	std::cout << "Encoded: " << outputString << "\n"
			  << std::flush;
	std::cout << "Decoded: " << messageEncDec.decode(outputString) << "\n"
			  << std::flush;
	std::cin.get();
	return 0;
}