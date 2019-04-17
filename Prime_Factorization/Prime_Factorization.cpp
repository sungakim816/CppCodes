#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // erase no more
#include <stdio.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>

void get_primes_below_sr_limit(std::vector<unsigned int> &stored_primes, unsigned int limit);
bool is_prime(std::vector<unsigned int> &stored_primes, unsigned int n);
void get_prime_factors(std::vector<unsigned int> &stored_primes, std::vector<unsigned int> &stored_factors, unsigned int user_input);

void get_primes_below_sr_limit(std::vector<unsigned int> &stored_primes, unsigned int limit)
{
    int n = 0;
    while (n <= limit)
    {
        if (is_prime(stored_primes, n))
        {
            stored_primes.push_back(n);
        }
        ++n;
    }
}

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
    else
    {
        for (iter = stored_primes.begin(); iter != stored_primes.end(); iter++)
        {
            if (n % *iter == 0)
            {
                return false;
            }
        }
        return true;
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

int main()
{
    unsigned int user_input = 0, p_factor = 0, sr_limit = 0;
    std::vector<unsigned int> stored_primes, stored_factors;
    std::string option = "";

    std::cout << "\t\t\tPrime Factorization\n\nEnter a number: ";
    std::cin >> user_input;
    sr_limit = sqrt(user_input);
    get_primes_below_sr_limit(stored_primes, sr_limit);
    get_prime_factors(stored_primes, stored_factors, user_input);

    if (stored_factors.size() == 1)
    {
        std::cout << "\n\nNo Other Factors other than 1 and itself\n\n";
    }
    else
    {
        std::cout << "\nPrime Factor/s of " << user_input << ":\n\n";
        for (unsigned int j = 0; j < stored_factors.size(); j++)
        {
            std::cout << stored_factors[j] << " ";
        }
    }
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
