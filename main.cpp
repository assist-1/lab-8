#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> prost(uint_fast64_t n2, uint_fast64_t n1) {
    std::vector<bool> prostie(n1 - n2, true);

    for (uint_fast64_t i = 2; i * i <= n1; i++) {
        for (uint_fast64_t j = i * i; j <= n1; j += i) {
            if (j >= n2) prostie[j - n2] = false;
        }
    }
    return prostie;
}

uint_fast64_t number_f(int ch) {
    return (ch*(ch-1)/2)+1;
}

int line_n(uint_fast64_t ch) {
    return std::ceil((-1+std::sqrt(1+8*ch))/2);
}

bool prog(int n, std::vector<bool> &prostie, uint_fast64_t low_b, uint_fast64_t pre_n = 0) {
    if (!prostie[n - low_b]) return false;

    int stroka = line_n(n);
    int pre_delta = 0;
    bool first_b = n == number_f(stroka);
    bool last_b = n == (number_f(stroka + 1) - 1);
    bool last_okolo = n == (number_f(stroka + 1) - 2);
    std::vector<int> del_vec;

    if (first_b) del_vec = {stroka - 1, stroka - 2, -stroka, -stroka - 1};
    else if (last_okolo) del_vec = {stroka, stroka - 1, -stroka + 1, -stroka, -stroka - 1};
    else if (last_b) del_vec = {stroka, -stroka + 1, -stroka, -stroka - 1};
    else del_vec = {stroka, stroka - 1, stroka - 2, -stroka + 1, -stroka, -stroka - 1};

    for (int delta : del_vec) {
        if (prostie[n - delta - low_b] && n - delta != pre_n) {
            if (pre_delta) return true;
            if (pre_n) return true;
            pre_delta = delta;
        }
    }

    if (!pre_delta) return false;
    else return prog(n - pre_delta, prostie, low_b, n);
}

uint_fast64_t B(int n) {
    uint_fast64_t ans = 0;
    uint_fast64_t low_b = number_f(n - 2);
    uint_fast64_t bord_top = number_f(n + 3) - 1;
    std::vector<bool> prostie = prost(low_b, bord_top);

    for (uint_fast64_t i = number_f(n); i < number_f(n + 1); ++i) {
        if (prog(i, prostie, low_b)) ans += i;
    }
    return ans;
}

int main()
{
    std::cout << B(10000) << std::endl;
    std::cout << B(5678027) + B(7208785) << std::endl;  //ответ на задачу
    return 0;
}