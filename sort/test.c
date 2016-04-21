#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

int main(){
	int A[SIZE]={0};
	int B[SIZE]={0};
	int n,i;
	clock_t t1,t2,t3,t4,t5,t6;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	printf("Data size: %d\n",n);
	/**************quicksort*************/
	for(i=0;i<n;i++){
		B[i]=A[i];
	}
	t1=clock();
	quicksort(B,0,n-1);
	t2=clock();
	is_sorted(B,0,n-1)==1?printf("Quicksort: Pass\n"):printf("Quicksort: Fail\n");
	/**********mergesort****************/
	for(i=0;i<n;i++){
		B[i]=A[i];
	}
	t3=clock();
	mergesort(B,0,n-1);
	t4=clock();
	is_sorted(B,0,n-1)==1?printf("Mergesort: Pass\n"):printf("Mergesort: Fail\n");
	/****************countingsort**********/
	for(i=0;i<n;i++){
		B[i]=A[i];
	}
	t5=clock();
	countingsort(B,0,n-1,0,1000);
	t6=clock();
	is_sorted(B,0,n-1)==1?printf("Countingsort: Pass\n"):printf("Countingsort: Fail\n");
	printf("Quicksort: %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);
	printf("Mergesort: %lf\n",(double)(t4-t3)/CLOCKS_PER_SEC);
	printf("Countingsort: %lf\n",(double)(t6-t5)/CLOCKS_PER_SEC);
	return 0;
}
