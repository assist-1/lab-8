#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
//простые до ≈50000


void printArray(int* array, int arraySize){
    for(int i=0;i<arraySize;i++){
        if(array[i]==-1)break;
        cout<<array[i]<<' ';
    }
    cout<< endl;
}

void fillPrimeArray(int primeSize,int* &primeArray){
    int positionNow=1;
    for(int i=0;i<primeSize;i++){
      primeArray[i]=-1;  
    }
    primeArray[0]=2;
    int border = 50000; //setting
    for(int i=3;i<=border;i++){
        bool Prime = false;
        for(int j=0;j<positionNow;j++){
            if(i%primeArray[j]==0){
                Prime=false;
                break;
            }
            else Prime = true;
        }
        if(Prime){
            primeArray[positionNow]=i;
            positionNow++;
        }
    }
}

bool isPrime(int primeSize, int* primeArray, int number){
    for(int i=0;i<primeSize;i++){
		if(primeArray[i]==-1)break;
		if(number==primeArray[i]) break;
		if(number%primeArray[i]==0){
			return 0;
		}
    }
    return 1;
}

int calcFirst(int n){
    int sum=1;
    for (int i=1;i<n;i++) sum+=i;
    return sum;
}

int calcLast(int first,int n){
    return first + (n-1);
}

bool circleCheck(int number,int n,int last,int primeSize,int* primeArray){
	int countPrime = 1;
	if(isPrime(primeSize,primeArray,number-n)) {countPrime++;}
	if(isPrime(primeSize,primeArray,number-1)) {countPrime++;}
	if(countPrime==3) return 1;
	if(isPrime(primeSize,primeArray,number+(n-1))) {countPrime++;}
	if(countPrime==3) return 1;
	if(isPrime(primeSize,primeArray,number+n)) {countPrime++;}
	if(countPrime>=3) return 1;
	if(isPrime(primeSize,primeArray,number+(n+1))) {countPrime++;}
	if(countPrime>=3) return 1;
	if(number!=last){
		if(isPrime(primeSize,primeArray,number+1)) {countPrime++;}
	}
	if(countPrime>=3) return 1;
	if(number<last-1){
		if(isPrime(primeSize,primeArray,number-(n-2))) {countPrime++;}
	}
	if(countPrime>=3) return 1;
	if(number!=last){
		if(isPrime(primeSize,primeArray,number-(n-1))) {countPrime++;}
	}
	if(countPrime>=3) return 1;
	return 0;
}																

int main(int argc, char** argv){
    int n = 8;
    int first = calcFirst(n);
    int last = calcLast(first,n);
    cout<<first<<"..."<<last<<endl;
    
    int primeSize = 50000; //setting
    int* primArray = new int[primeSize];
    fillPrimeArray(primeSize,primArray);
    long long int sum = 0;
    for(int i=first;i<=last;i++){ //setting
		if(i%2==0)continue;
        if(isPrime(primeSize,primArray,i)){
			if(circleCheck(i,n,last,primeSize,primArray)) cout<<i<<' '<<endl;
        }
    }
    
    cout<<sum<<endl;
    delete[] primArray;
    return 0;
}