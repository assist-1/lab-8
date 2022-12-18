#include "functions.hpp"

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long mul(long long a, long long b, long long m) {
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        long long t = mul(a, b / 2, m);
        return (2 * t) % m;
    }
    return (mul(a, b - 1, m) + a) % m;
}

long long pows(long long a, long long b, long long m) {
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        long long t = pows(a, b / 2, m);
        return mul(t, t, m) % m;
    }
    return (mul(pows(a, b - 1, m), a, m)) % m;
}

bool ferma(long long x) {
    if (x == 2)
        return true;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        long long a = (rand() % (x - 2)) + 2;
        if (gcd(a, x) != 1)
            return false;
        if (pows(a, x - 1, x) != 1)
            return false;
    }
    return true;
}

long long SumProstNumber(long long n) {
    long long begining = n * (n - 1) / 2 + 1;
    if (begining % 2 == 0) {
        ++begining;
    }
    long long sum = 0;
    for (long long i = begining; i < begining + n; i = i + 2) {
        if (ferma(i) && isinMagicTriple(i, n)) {
            sum += i;
        }
    }
    return sum;
}

bool isinMagicTriple(long long x, long long n) {
    if (ferma(x - (n - 1)) && (ferma(x - 2 * (n - 1)) || ferma(x - 2 * (n - 2)) || ferma(x+n-1) || ferma(x+n+1))) {
        return true;
    }
    if (ferma(x + n) && (ferma(x + 2 * n) || ferma(x + 2 * n + 2))) {
        return true;
    }
    if (ferma(x + n - 1) && (ferma(x + 2 * n) || ferma(x + n + 1) || ferma(x - 2))) {
        return true;
    }
    if (ferma(x + n + 1) && (ferma(x + 2 * n + 2) || ferma(x - 2))) {
        return true;
    }
    if (ferma(x - n) && (ferma(x - 2 * n + 2) || ferma(x - n + 2) || ferma(x + n) || ferma(x-2))) {
        return true;
    }
    if (ferma(x - n + 2) && (ferma(x - 2 * n + 4) || ferma(x + n) || ferma(x+2))) {
        return true;
    }
    return false;
}