#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
/*
iterate number i from 1 to n
if i is prime number, skip it and continue
if i is not a prime number, get all its prime factors and save in an array
count unique factors from the array, if count is equal to 4 increment count variable;
*/
bool is_prime(std::vector<unsigned int> &stored_primes, unsigned int n);
void get_primes_below_sr_limit(std::vector<unsigned int> &stored_primes, unsigned int limit);
void get_prime_factors(std::vector<unsigned int> &stored_primes, std::vector<unsigned int> &stored_factors, unsigned int user_input);

bool is_prime(std::vector<unsigned int> &stored_primes, unsigned int n)
{
	std::vector<unsigned int>::iterator iter;
	if (n < 2)
	{
		return false;
	}
	else if (n == 2)
	{
		return true;
	}
	else if (std::binary_search(stored_primes.begin(), stored_primes.end(), n))
	{
		return true;
	}
	else
	{
		iter = stored_primes.begin();
		while (iter != stored_primes.end())
		{
			if (n % *iter == 0)
			{
				return false;
			}
			iter++;
			if (*iter > (n >> 1))
				break;
		}
		return true;
	}
}

void get_primes_below_sr_limit(std::vector<unsigned int> &stored_primes, unsigned int limit)
{
	unsigned int n = 0;
	while (n <= limit)
	{
		if (is_prime(stored_primes, n))
		{
			stored_primes.push_back(n);
		}
		++n;
	}
}

void get_prime_factors(std::vector<unsigned int> &stored_primes, std::vector<unsigned int> &stored_factors, unsigned int user_input)
{
	std::vector<unsigned int>::iterator divisor;
	divisor = stored_primes.begin();
	while (divisor != stored_primes.end())
	{
		if (user_input % *divisor == 0)
		{
			stored_factors.push_back(*divisor);
			user_input = user_input / *divisor;
		}
		else
		{
			*divisor++;
		}
	}
	if (user_input != 1)
		stored_factors.push_back(user_input);
}
int main(int argc, char *argv[])
{
	unsigned int input = 0, sr_limit = 0, limit = 200000;
	unsigned short unique_factor_count = 4;
	unsigned count = 0;
	std::vector<unsigned int> stored_primes, stored_factors;
	sr_limit = sqrt(limit);
	get_primes_below_sr_limit(stored_primes, sr_limit);
	std::unordered_set<unsigned int> unique_factors;
	for (unsigned i = 2; i < limit; i++)
	{
		input = i;
		if (!is_prime(stored_primes, i))
		{
			get_prime_factors(stored_primes, stored_factors, input);
			std::copy(
				stored_factors.begin(), stored_factors.end(),
				std::inserter(unique_factors, unique_factors.end()));
			if (unique_factors.size() == unique_factor_count)
			{
				count++;
			}
			else
			{
				count = 0;
			}
		}
		else
		{
			count = 0;
		}
		unique_factors.clear();
		stored_factors.clear();
		if (count == unique_factor_count)
		{
			std::cout << (i - 3) << std::endl;
		}
	}
	return 0;
}
