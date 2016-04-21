#include<cstdio>
#include<cmath>
#include<bitset>
#define SIZE 100000
using namespace std;

bitset<SIZE+1> isPrime; //index start with 0

void sieve(int n){
    isPrime.set();
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=4;i<=n;i+=2){ //discarding all even numbers
        isPrime[i]=0;
    }
    for(int i=3;i*i<=n;i+=2){ /* checking all odd
    							     number less than sqrt(n)*/
        if(isPrime[i]){
            for(int j=i*i;j<=SIZE;j += i){ /* discarding all multiple
            								  of i starting from i^2, upto SIZE*/
                isPrime[j]=0;
            }
        }
    }
}

void primeFactor(int n){
	sieve(sqrt(n)); //sieving all prime numbers 
					//less than or equal to sqrt(n)
	int m=n;
	for(int i=2;i*i<=n;i++){ //checking divisibilty of
							 //all prime less than or equal
							 //to sqrt(n) with n
		if(isPrime[i]){
			while(m%i==0){
				printf("%d*",i);
				m=m/i;
			}
		}
	}
	if(m>1)
		printf("%d",m);
}
int main(){
	int n=1856248526;
	primeFactor(n);
	return 0;
}
