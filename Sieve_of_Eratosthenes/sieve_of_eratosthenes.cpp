#include <iostream>
#include <string>
#include <vector>
#include <algorithm>// erase no more
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include <sstream>

void get_primes_below_sr_limit(std::vector <int>& stored_primes, int limit, int64_t &sum);
bool is_prime(std::vector <int>& stored_primes, int n);

void get_primes_below_sr_limit(std::vector <int>& stored_primes, int limit, int64_t &sum)
{   int i = 0;
    while (i<=limit)
    {
        if (is_prime(stored_primes, i))
        {
            sum += i;
            stored_primes.push_back(i);
        }
        ++i;
    }
}

bool is_prime(std::vector <int>& stored_primes, int n)
{
    std::vector <int>::iterator iter;
    if (n < 2)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }else
    {
        int sqr = sqrt(n);
        for (iter = stored_primes.begin(); iter != stored_primes.end(); iter++)
        {
            if (*iter > sqr){
                return true;
            }
            else if (n % *iter == 0)
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{   std::vector <int> stored_primes;
    int64_t sum = 0;
    int n = 0, limit = 2000000, sr_limit = 0;
    sr_limit = sqrt(limit);
    get_primes_below_sr_limit(stored_primes, sr_limit, sum);// get all primes below sr limit
    n = stored_primes.back();
    if (n % 2 == 0) n+=3;
    else if (n % 2 == 1) n+=2;
    while (n<=limit)
    {
        if (is_prime(stored_primes, n))
        {
            sum += n;
        }
        n+=2;
    }
    std::cout << "\nSum of all prime numbers below 2,000,001: " << sum << "\n";
    return 0;
}
