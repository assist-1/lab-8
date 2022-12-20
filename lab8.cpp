#include <iostream>
#include <math.h>

using namespace std;

long first_digit(int n) 
{
    long summ = 1;
    for (int i = 1; i < n; i++) 
    {
        summ += i;
    }
    return summ;
}

bool prime_check(int n) 
{
    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (n % i == 0) 
            return 0;
    }
    return 1;
}

int magic_check(int i, int n, int deep, int first) 
{
    if (deep == 0) return 0;
    int quont = 0;
    if (prime_check(i - n) and i != first) 
    {
        quont++;
        if (magic_check(i - n, n - 1, deep - 1, first - n + 1) > 1)
            quont++;
    }
    if (prime_check(i - n + 1) and i != first + n - 1) 
    {
        quont++;
        if (magic_check(i - n + 1, n - 1, deep - 1, first - n + 1) > 1)
            quont++;
    }
    if (prime_check(i - n + 2) and i != first + n - 1) 
    {
        quont++;
        if (magic_check(i - n + 2, n - 1, deep - 1, first - n + 1) > 1)
            quont++;
    }
    if (prime_check(i + n)) 
    {
        quont++;
        if (magic_check(i + n, n + 1, deep - 1, first + n) > 1)
            quont++;
    }
    if (prime_check(i + n - 1) and i != first) 
    {
        quont++;
        if (magic_check(i + n - 1, n + 1, deep - 1, first + n) > 1)
            quont++;
    }
    if (prime_check(i + n + 1)) 
    {
        quont++;
        if (magic_check(i + n + 1, n + 1, deep - 1, first + n) > 1)
            quont++;
    }
    return quont;
}

long B(int n) 
{
    long summ = 0;
    long first = first_digit(n);
    for (long i = first; i < first + n; i++) 
    {
        if (prime_check(i)) 
        {
            if (magic_check(i, n, 2, first) > 1) summ += i;
        }
    }return summ;
}

int main()
{
    long final = B(5678027) + B(7208785);
    cout << final;
} 