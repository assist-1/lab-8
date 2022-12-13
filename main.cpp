#include <iostream>
int a,b;
double fraction=(3.0/7.0);
double min_raz=1000000.0;
int main(){
for(int p=2;p<=1000000;p++){
    double n=fraction*p;
    n = int(n);
    if((fraction-n/p)==0){
        continue;
    }
    if((fraction-n/p)<min_raz){
        min_raz=fraction-n/p;
        a=n;
        b=p;
    } 
}
std::cout<<a<<"/"<<b<<'\n';
return 0;
}