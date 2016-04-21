#include<stdio.h>
#include"myheap.h"
/*#include"max_heapify.c"*/
/*#include"build_max_heap.c"*/
/*#include"heapsort.c"*/

int main(){
	int A[10];
	size_t i=0;
	printf("Enter Array element: ");
	for(i=0;i<10;i++){
		scanf("%d",&A[i]);
	}
	heapsort(A,10);
	for(i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
