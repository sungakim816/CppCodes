#include "pypert.h"

unsigned int factorial(unsigned n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

unsigned int gcf(unsigned int lower, unsigned int upper)
{
    if (lower > upper)
    {
        unsigned int temp = lower;
        upper = lower;
        lower = temp;
    }
    if (upper % lower == 0)
        return lower;
    else
        return gcf(upper % lower, lower);
}

unsigned int lcm(unsigned int lower, unsigned int upper)
{
    return lower * upper / gcf(lower, upper);
}

unsigned int digitSumHelper(unsigned int n, unsigned int digitSum)
{
    if (n == 0)
        return digitSum;
    digitSum += (n % 10);
    n /= 10;
    return digitSumHelper(n, digitSum);
}

unsigned int digitSum(unsigned int num)
{
    return digitSumHelper(num, 0);
}

void swap(int &var1, int &var2)
{
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

void swap(unsigned int &var1, unsigned int &var2)
{
    unsigned int temp = var1;
    var1 = var2;
    var2 = temp;
}

void swap(float &var1, float &var2)
{
    float temp = var1;
    var1 = var2;
    var2 = temp;
}

void swap(double &var1, double &var2)
{
    double temp = var1;
    var1 = var2;
    var2 = temp;
}

void swap(std::string &var1, std::string &var2)
{
    std::string temp = var1;
    var1 = var2;
    var2 = temp;
}