#include <iostream>

int main() {
    double aim = 3. / 7.;

    // (m / n)

    int p;
    int k;
    double closest = 0;
    double cur_closest = 0;
    double m, n;

    double delta;
    double delk;
    for (p = 2; p < 1000000; ++p) {
        delta = 1. / p;
        delk = aim / delta;
        k = delk;
        cur_closest = static_cast<double>(k) / p;
        if (cur_closest >= aim || !k) continue; 
        if (aim - closest > aim - cur_closest) {
            m = k; n = p;
            closest = cur_closest;
        }
    }

    std::cout << "Answer: " << m << " / " << n << std::endl;
    return 0;
}
