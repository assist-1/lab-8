#include <iostream>
#include <cmath>

using namespace std;
double sum(int n) {
    long res = 0;
    for (int i = 1; i < n + 1; i++) {
        res += i;
    }return res;
}
bool isprime(int n) {
    if (n <= 1) {
        return 0;

    }
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int counter(int i, int n, int begin, int low) {
    if (low == 0) return 0;
    long long res = 0;
    if (isprime(i - n) and i != begin) {
        res++;
        if (counter(i - n, n - 1, begin -1, low -1) > 1)res++;
    }
    if (isprime(i - n + 1) and i != begin + n - 1) {
        res++;
        if (counter(i - n + 1, n - 1, begin - n + 1, low -1 ) > 1)res++;
    }
    if (isprime(i - n + 2) and i != begin + n - 1) {
        res++;
        if (counter(i - n + 2, n - 1, begin - n + 1, low -1) > 1)res++;
    }
    if (isprime(i - 1) and i != begin) {
        res++;
        if (counter(i - 1, n, begin, low-1) > 1)res++;
    }
    if (isprime(i + 1) and i != begin + n - 1) {
        res++;
        if (counter(i + 1, n, begin, low-1) > 1)res++;
    }
    if (isprime(i + n)) {
        res++;
        if (counter(i + n, n + 1, begin + n, low-1) > 1)res++;
    }
    if (isprime(i + n - 1) and i != begin) {
        res++;
        if (counter(i + n - 1, n + 1, begin + n, low - 1) > 1)res++;
    }
    if (isprime(i + n + 1)) {
        res++;
        if (counter(i + n + 1, n + 1, begin + n, low - 1) > 1)res++;
    }
    return res;
}

double B(int n) {
    long start = sum(n - 1) + 1;
    long res = 0;
    for (long i = start; i < start + n; i++) {
        if (isprime(i)) {
            if (counter(i, n, start,2) >= 2) res += i;
        }
    }return res;
}

int main()
{
    cout << B(5678027) + B(7208785);
}