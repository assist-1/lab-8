#include <cmath>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int getline(uint64_t n) {
    int a = ceil((-1 + std::sqrt(1 + 8 * n)) / 2);
    return a;
}

uint64_t getfirst(int c) {
    uint64_t b = c * (c - 1) / 2 + 1;
    return b;
}

vector<bool> erat(uint64_t n, uint64_t k) {
    std::vector <bool> pr(k - n, true);
    for (uint64_t p = 2; p * p <= k; p++) {
        for (uint64_t i = p * p; i <= k; i += p)
            if (i >= n) pr[i - n] = false;
    }
    return pr;
}

bool right(int n, vector<bool>& pr, uint64_t lower_border, uint64_t prev_n = 0) {
    if (!pr[n - lower_border]) return false;
    int line = getline(n);
    bool is_first = (n == getfirst(line));
    bool is_last = (n == (getfirst(line + 1) - 1));
    bool is_near_last = (n == (getfirst(line + 1) - 2));
    int delta_prev = 0;
    vector <int> deltas;
    if (is_first) {
        deltas = { line - 1, line - 2, -line, -line - 1 };
    }
    else if (is_near_last) {
        deltas = { line, line - 1, -line + 1, -line, -line - 1 };
    }
    else if (is_last) {
        deltas = { line, -line + 1, -line, -line - 1 };
    }
    else {
        deltas = { line, line - 1, line - 2, -line + 1, -line, -line - 1 };
    }

    for (int delta : deltas) {
        if (pr[n - delta - lower_border] && n - delta != prev_n) {
            if (delta_prev) return true;
            if (prev_n) return true;
            delta_prev = delta;
        }
    }

    if (!delta_prev) return false;
    else return right(n - delta_prev, pr, lower_border, n);
}

uint64_t B(int n) {
    uint64_t ending = 0;
    uint64_t lower_border = getfirst(n - 2);
    uint64_t top_border = getfirst(n + 3) - 1;
    vector <bool> pr = erat(lower_border, top_border);
    for (uint64_t i = getfirst(n); i < getfirst(n + 1); i++) {
        if (right(i, pr, lower_border)) {
            ending += i;
        }
    }
    return ending;
}

int main() {
    int q = 5678027;
    int w = 7208785;
    cout << B(q) + B(w) << endl;
    return 0;
}