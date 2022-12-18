#include <iostream>
#include <set>
#include <fstream>
#include <vector>

using std::vector;

int del3 (long long int num){
    long long int numv = num;
    while (numv / 10 > 1){
        num = numv;
        numv = 0;
        while (num != 0) {
            numv += num % 10;
            num = num / 10;
        }
    }
    if ((numv - 7) % 3 == 0)
        return (numv - 7) % 3;
    else
        return numv % 3;
}

int del8 (long long int num){
    return ((num % 1000) % 8);
}



int main() {
    std::ofstream fout;
    fout.open("output.txt");
    std::set <long long int> prime_number;
    long long int n = 7208785 * 7208785;
    vector<bool> prime (n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
            prime_number.insert(i);
            fout << i << " ";
        }
}
