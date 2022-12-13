#include <iostream>
using std::cout;
using std::endl;
int  a,       //    числитель левой дроби
     b,       //  знаменатель левой дроби
     c = 3,   //    числитель средней дроби
     d = 7;   //  знаменатель средней дроби

int MaxDenominator(int);
int NOD(int k, int p);
 
int main()
{
    int res = MaxDenominator(1000000);
    if(res == 1 && NOD(a,b) == 1)
        cout << "The fraction to the left of 3/7 is "<< a <<"/"<< b <<std::endl;
}
 
int MaxDenominator(int nMaxD)
{
    nMaxD -= 12; // промежуток между данным заменателем и знаменателем 12, с которого                  начинается закономерность
    int d = nMaxD % 7;
    nMaxD -= d;
    a = (nMaxD * 3)/7 + 5;   //  Найден числитель левой дроби
    b = nMaxD + 12;          //  Найден знаменатель левой дроби
         
return 1;
}
//  47 - 12 = 35
//  35 / 7 =  5 - период закономерности
//   5 * 3 + 5 = 20 = числитель
//   5 * 7 + 12 = 47 = знаменатель

int NOD(int k, int p)   // k-числитель, p-знаменатель
{
    if(k >= p)
        return 0;  //  Числитель не меньше знаменателя
    
    while(p > 0)
    {
        int c = k % p; //  Алгоритм Евклида (НОД)
        k = p;
        p = c;
    }
    if(k != 1)
        return 0;    //  Есть общий множитель больше единицы
    return 1;
}
