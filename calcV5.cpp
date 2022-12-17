#include <iostream>
#include <cmath>
#include <vector>
using std::cin;
using std::cout;
using std::endl;


void printArray(int* array, unsigned long arraySize){
    for(unsigned long i=0;i<arraySize;i++){
        if(array[i]==-1)break;
        cout<<array[i]<<' ';
    }
    cout<< endl;
}
void printArray(bool* array, unsigned long arraySize){
    for(unsigned long i=0;i<arraySize;i++){
        if(array[i]==-1)break;
        cout<<array[i]<<' ';
    }
    cout<< endl;
}

unsigned long long T(unsigned long long x,unsigned long long y){
	return (x*(x+1)/2);
}
unsigned long long MinNUM = 0;

void fillPrime2022(unsigned long long lastNumber, std::vector<unsigned long long>* primOneA) {
	const unsigned long long CountElt = (lastNumber-1)/2+1;
	
	std::vector<bool> separt;

	separt.resize(CountElt, 1);
	
	for (unsigned long long i = 3; i*i <= lastNumber; i += 2)     
		if (separt[i/2])          
			for (unsigned long long j = i*i; j <= lastNumber; j += 2*i) separt[j/2] = 0;   
 

	primOneA->clear();

	primOneA->push_back(2);
	
	for (unsigned long long  i = 1; i <= CountElt; i++) if (separt[i]) primOneA->push_back(i*2+1);   

}

void fillPrimeArray(std::vector<unsigned long long> primeOneA,std::vector<unsigned long long>* primeTwoA,unsigned long long line){
	::MinNUM = T(line-3,1) + 1;
	unsigned long long MaxNUM = T(line+2,1);
	std::vector<bool> separt2;
	separt2.resize(MaxNUM-MinNUM+1, 1);
 
	for (unsigned long long i=0; i<primeOneA.size(); i++) {
		unsigned long long h = MinNUM % primeOneA[i];
		unsigned long long j = h == 0 ? 0 : primeOneA[i] - h;
		for (; j<=MaxNUM-MinNUM; j+=primeOneA[i]) separt2[j] = 0;
	}

	for (unsigned long long  i = 0; i < separt2.size(); i++) primeTwoA->push_back(separt2[i]) ;
}

bool isPrime(std::vector<unsigned long long>* primeArray, unsigned long long number){
	if((number-MinNUM<primeArray->size())&&primeArray->at(number-MinNUM)) return 1;
	else return 0;
}




unsigned long long getNumber(unsigned long long xPos,unsigned long long yPos){
	if(yPos<=xPos){
		unsigned long long answer = T(xPos,yPos) - (xPos-yPos);
		return answer;
	}
	else{
		return 1;
	}
}

void fillBoolPrimes(std::vector<unsigned long long>* primeArray,bool* &primeLine,unsigned long long line){
	for(unsigned long long i=0;i<line;i++){
		if(isPrime(primeArray,getNumber(line,i+1))){
			primeLine[i]=1;
		}
		else{
			primeLine[i]=0;
		}
	}
}

bool ohATriple(unsigned long long number){
	if(number>=2) return 1;
	else return 0;
}

void clearBoolArray(bool* &array,unsigned long long size){
	for(unsigned long long i=0;i<size;i++){
		array[i]=0;
	}
}

void checkLine(bool* &Line,unsigned long long size,std::vector<unsigned long long>* primeVector){
	clearBoolArray(Line,size);
	for(unsigned long long i=0;i<size;i++){

		if(getNumber(size,i+1)%2==0) continue;

		if(isPrime(primeVector,getNumber(size,i+1))){
			
			unsigned long long  countPrimes = 1;
			for(int delx=-1;delx<=1;delx++){
				if((i+1)+delx>=1){

					if((size-1)>=((i+1)+delx)){
						if(isPrime(primeVector,getNumber(size-1,(i+1)+delx))) countPrimes++;
					}
					if((size+1)>=((i+1)+delx)){
						if(isPrime(primeVector,getNumber(size+1,(i+1)+delx))) countPrimes++;
					}
				}
			}
			if(countPrimes>=3) Line[i]=1;
		}
	}
}

unsigned long long countMainLine(bool* UpperLine,bool* LowLine,bool* MainLine,unsigned long long n,std::vector<unsigned long long>* primeVector){
	unsigned long long sum = 0;
	for(unsigned long long i=0;i<n;i++){
		if(MainLine[i]==1) {sum+= getNumber(n,i+1);continue;}
		if(getNumber(n,i+1)%2==0) continue;
		if(isPrime(primeVector,getNumber(n,i+1))){
			unsigned long long countPrimes = 1;
			for(int delx=-1;delx<=1;delx++){
				if((i+1)+delx>=1){

					if((n-1)>=((i+1)+delx)){
						if(UpperLine[i+delx]==1) countPrimes++;
					}
					if((n+1)>=((i+1)+delx)){
						if(LowLine[i+delx]==1) countPrimes++;
					}
				}
			}
			if(countPrimes>=2) sum+= getNumber(n,i+1);
		}
	}
	return sum;
}

unsigned long long Bn(std::vector<unsigned long long>* primeVector,unsigned long long n){
	bool* UpperLine = new bool[n-1];
	bool* LowLine = new bool[n+1];
	bool* MainLine = new bool[n];
	
	checkLine(UpperLine,n-1,primeVector);

	
	checkLine(LowLine,n+1,primeVector);

	
	checkLine(MainLine,n,primeVector);
	
	return countMainLine(UpperLine,LowLine,MainLine,n,primeVector);
}

int main(int argc, char** argv){

	unsigned long long sum = 0;
	unsigned long long n1 = 5678027;
	unsigned long long n2 = 7208785;
	std::vector<unsigned long long> primArray;
	fillPrime2022(sqrt(T(n1+2,1)),&primArray);
	std::vector<unsigned long long> localPrimeArray;
	fillPrimeArray(primArray,&localPrimeArray,n1);
	sum += Bn(&localPrimeArray,n1);
	
	primArray.clear();
	localPrimeArray.clear();
	fillPrime2022(sqrt(T(n2+2,1)),&primArray);
	fillPrimeArray(primArray,&localPrimeArray,n2);
	sum += Bn(&localPrimeArray,n2);
	cout << sum ;

	localPrimeArray.clear();
	primArray.clear();

    return 0;
}