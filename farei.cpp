#include <iostream>

using namespace std;

int main() {
    int a = 3;
    int b = 7;
    int x1 = 0;
    int x2 = 1;
    int y1 = 1;
    int y2 = 1;
    int N = 1000000;
    while (true) {
        int m1 = x1 + y1;
        int m2 = x2 + y2;
        if (m1 == a && m2 == b) {
            y1 = a;
            y2 = b;
            break;
        }
        if (m1*b - m2*a > 0) {
            y1 = m1;
            y2 = m2;
        } else {
            x1 = m1;
            x2 = m2;
        }
    }

    while (x2 + b <= N) {
        x1 += a;
        x2 += b;
    }

    cout << "Дробь слева равна " << x1 << " / " << x2 << endl;
}