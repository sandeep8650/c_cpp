//bitwise optimized sieve implementation
#include<iostream>
#include<bitset>
#include<cmath>
#define SIZE 349900
#define LIMIT sqrt(SIZE)
using namespace std;

bitset<SIZE+1> isPrime; //index start with 0

void sieve(){
    isPrime.set();
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=4;i<=SIZE;i+=2){ //discarding all even numbers
        isPrime[i]=0;
    }
    for(int i=3;i<=LIMIT;i+=2){  /* checking all odd
    							     number less than sqrt(n)*/
        if(isPrime[i]){
            for(int j=i*i;j<=SIZE;j += i){ /* discarding all multiple
            								  of i starting from i^2, upto SIZE*/
                isPrime[j]=0;
            }
        }
    }
}


int main(){
    sieve();
    for(int i=0;i<=SIZE;i++){
        if(isPrime[i]){
            cout<<i<<"\n";
        }
    }
    cout<<endl;
}
