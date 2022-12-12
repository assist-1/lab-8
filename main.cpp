#include <iostream>

using std::cout;

int main() {
    double min_delta = 179.0;
    int ans_q, ans_p;
    for (double p = 2; p <= 1000000; ++p) {
        double q  = 3.0 / 7.0 * p;
        q = (int)q;
        double delta = (3.0 / 7.0) - ((double)q / p);
        if (delta == 0) {
            continue;
        }
        if (min_delta > delta) {
            min_delta = delta;
            ans_q = q;
            ans_p = p;
        }
    }
    cout << min_delta << '\n' << ans_q << '/' << ans_p;
    return 0;
}