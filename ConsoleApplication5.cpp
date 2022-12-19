#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

bool easy(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }return 1;
}

int counter(int i, int n, int deep, int start) {
    if (deep == 0) return 0;
    int points = 0;
    if (easy(i - n) and i != start) {
        points++;
        if (counter(i - n, n - 1, deep - 1, start - n + 1) > 1)points++;
    }
    if (easy(i - n + 1) and i != start + n - 1) {
        points++;
        if (counter(i - n + 1, n - 1, deep - 1, start - n + 1) > 1)points++;
    }
    if (easy(i - n + 2) and i != start + n - 1) {
        points++;
        if (counter(i - n + 2, n - 1, deep - 1, start - n + 1) > 1)points++;
    }
    if (easy(i - 1) and i != start) {
        points++;
        if (counter(i - 1, n, deep - 1, start) > 1)points++;
    }
    if (easy(i + 1) and i != start + n - 1) {
        points++;
        if (counter(i + 1, n, deep - 1, start) > 1)points++;
    }
    if (easy(i + n)) {
        points++;
        if (counter(i + n, n + 1, deep - 1, start + n) > 1)points++;
    }
    if (easy(i + n - 1) and i != start) {
        points++;
        if (counter(i + n - 1, n + 1, deep - 1, start + n) > 1)points++;
    }
    if (easy(i + n + 1)) {
        points++;
        if (counter(i + n + 1, n + 1, deep - 1, start + n) > 1)points++;
    }
    return points;
}

long help(int n) {
    long res = 0;
    for (int i = 1; i < n + 1; i++) {
        res += i;
    }return res;
}

long B(int n) {
    long start = help(n - 1) + 1;
    long res = 0;
    for (long i = start; i < start + n; i++) {
        if (easy(i)) {
            if (counter(i, n, 2, start) >= 2) res += i;
        }
    }return res;
}

int main()
{
    cout << B(5678027) + B(7208785);
}