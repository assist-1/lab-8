#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int znamenatel(int q) {
    while (((q - 5) % 7) != 0) {
        q -= 1;
    }
    return q;
}

void schet(int n)
{
    int dr[2];
    double max_el = 0;
    int q = 0;
    for (double i = 2; i < n; i += 3)
    {
        double j = znamenatel(n);
        if ((gcd(i, j) == 1) && ((i / j) < ((double)3 / (double)7)) && (max_el < (i / j)))
        {
            max_el = i / j;
            dr[0] = i;
            dr[1] = j;
        }

    }
    cout << dr[0] << "/" << dr[1] << endl;
}

int main()
{
    int n = 1000000;//можно ввести почти любой знаменатель (100 000 000 считает за 8 сек)
    schet(n);
    return 0;
}