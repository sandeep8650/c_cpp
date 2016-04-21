#include<iostream>
#include<limits>
using namespace std;

void maxmin(int A[],int s,int e,int *max,int *min){
	if(s<=e){
		if(*max<A[s]){
			*max = A[s];
		}
		if(*min>A[s]){
			*min = A[s];
		}
		maxmin(A,s+1,e,max,min);
	}
}

int main(){
	int max=numeric_limits<int>::min();
	int min=numeric_limits<int>::max();
	int A[]={9,8,7,6,5,4,3,2,1};
	maxmin(A,0,8,&max,&min);
	cout<<"max="<<max<<" min="<<min<<"\n";
	return 0;
}
