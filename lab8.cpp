#include <math.h>
#include <iostream>

struct Row{
    long long begin;
    long long end;
    long long row;
    long long prev_minus_end;
    long long next_minus_end;


    Row(long long n){
        begin = n * (n - 1) / 2 + 1;
        end = begin + n - 1;
        row = n;
        prev_minus_end = -n;
        next_minus_end = n + 1;
    }
};

long long ifNumPrime(long long num){
    for (long long i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return num;
}

void makeNeighbour(Row& row, long long *neighbours_arr, long long num){ 
    if (num != row.begin){
        neighbours_arr[0] = row.prev_minus_end + num;
        neighbours_arr[3] = num - 1;
        neighbours_arr[5] = row.next_minus_end + num - 2;
    }
    if (num != row.end){
        neighbours_arr[1] = row.prev_minus_end + num + 1;
        neighbours_arr[4] = num + 1;
        neighbours_arr[6] = row.next_minus_end + num - 1;

    }
    if (num < row.end - 1){
        neighbours_arr[2] = row.prev_minus_end + num + 2;

    }
    neighbours_arr[6] = row.next_minus_end + num - 1;
    neighbours_arr[7] = row.next_minus_end + num;
}

long long ifNumInChain(Row& a, long long num, int checker){
    long long k = ifNumPrime(num);
    if (k){
        long long primeNeighbour = 0;
        long long primeNeighboursRow = 0;
        long long arr[8] = {};
        int t = 0;
        makeNeighbour(a, arr, num);
        for (int j = 0; j < 8; ++j){
            if (ifNumPrime(arr[j])){
                t += 1;
                primeNeighbour = arr[j];
                if (j < 3){
                    primeNeighboursRow = a.row - 1;
                }
                else if (j < 5){
                    primeNeighboursRow = a.row;
                }
                else{
                    primeNeighboursRow = a.row + 1;
                }
                if (t >= 2){
                    return k;
                }
            }
        }
        if (t == 1){
            if (checker){
                Row h(primeNeighboursRow);
                if (ifNumInChain(h, primeNeighbour, 0)){
                    return k;
                }
            }
        }
    }
    return 0;
}


int main(){
    long long summa = 0;
    Row a(10000);
    for (long long i = a.begin + 1; i <= a.end; ++i){
        summa += ifNumInChain(a, i, 1);
    }
    std::cout << summa;
}