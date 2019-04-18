#include <iostream>

unsigned int digitSumRecursionHelper(unsigned int n, unsigned int digitSum)
{
	if (n == 0)
		return digitSum;
	digitSum += (n % 10);
	n /= 10;
	return digitSumRecursionHelper(n, digitSum);
}

unsigned int digitSumRecursion(unsigned int num)
{
	return digitSumRecursionHelper(num, 0);
}

int main(int argc, char *argv[])
{
	unsigned int userInput = 9909;
	std::cout << "Digit Sum (Recursion)" << std::endl
			  << std::endl;
	std::cout << "Enter a positive Integer: " << std::flush;
	std::cin >> userInput;
	std::cout << "Sum of digits of " << userInput << ": " << digitSumRecursion(userInput) << std::endl;
	return 0;
}
