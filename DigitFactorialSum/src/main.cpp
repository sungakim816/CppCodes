#include <iostream>
#include <algorithm>
#include <string>
#include "pypert.h"

int main(int argc, char *argv[])
{
	std::string x = "Kim", y = "Sunga";
	swap(x, y);
	int *pInt = nullptr;
	pInt = new int(16);
	int *pString = (int *)malloc(sizeof(int) * 5);
	std::cout << x << " " << y << std::endl;
	std::cout << pInt << std::endl;
	std::cout << pString << std::endl;
	delete pInt;
	pInt = nullptr;
	pInt = new int(32);
	std::cout << pInt << std::endl;
	delete pInt;
	pInt = nullptr;
	return 0;
}