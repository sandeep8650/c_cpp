#include"sort.h"

void countingsort(int A[], int start, int end, int min, int max){	
	int count[SIZE]={0};
	int B[SIZE]={0};
	int i;
	for(i=start;i<=end;i++){
		count[A[i]-min]++;
	}
	for(i=1;i<=max-min;i++){
		count[i] += count[i-1];
	}
	for(i=end;i>=start;i--){	
		B[--count[A[i]-min]]=A[i];
	}
	for(i=start;i<=end;i++){
		A[i] = B[i-start];
	}
}
