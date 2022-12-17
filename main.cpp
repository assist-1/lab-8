#include <iostream>

int main()
{
    double num = 3. / 7.;
    int p;
    int k;
    double closest = 0;
    double current = 0;
    double count, queff, m, n;
    for (p = 2; p < 1000000; ++p) {
        count = 1. / p;
        queff = num / count; // узнаем на сколько число num больше текущего числа
        k = queff;
        current = static_cast<double>(k) / p; // получаем число  близкое к  числу num; static_cast<double>(int k) приведение типа инт к дабл
        if (current >= num || !k) continue;
        if (num - closest > num - current) // если разница между closest и num  больше чем num и current, то:
        {
            m = k;
            n = p;
            closest = current;
        }
    }
    std::cout << "Answer: " << m << " / " << n << std::endl;
    return 0;
}