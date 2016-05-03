#include"sort.h"

int merge(int A[],int a1,int a2,int b1,int b2){
	int B[SIZE]={0};
	int i=a1,j=b1,k=0;
	while((i<=a2)&&(j<=b2)){
		if(A[i]<A[j]){
			B[k++]=A[i++];
		}
		else{
			B[k++]=A[j++];
		}
	}
	if(i>a2){
		while(j<=b2){
			B[k++]=A[j++];
		}
	}
	else{
		while(i<=a2){
			B[k++]=A[i++];
		}
	}
	while(k--){
		A[k+a1] = B[k];
	}
	return 0;
}

int mergesort(int A[],int left,int right){
	int mid = (left+right)/2;
	if(left<right){
		mergesort(A,left,mid);
		mergesort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
	}
	return 0;
}
