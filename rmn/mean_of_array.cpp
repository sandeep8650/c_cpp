#include<iostream>

using namespace std;

float mean(float A[],int s,int e,int size){
	if(s<=e){
		return A[s]/size + mean(A,s+1,e,size);
	}
	return 0;
}

int main(){
	float A[]={1,2,3,4,5,6,7,8,9};
	cout<<mean(A,0,8,9)<<"\n";
}
