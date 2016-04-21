#include<stdio.h>
#include"priority_queue.h"

//#define isPowerOfTwo(S) (!(S & (S - 1)))

int print_heap(int A[],int heap_size){
	int i=0;
	if(heap_size<1){
		printf("Heap is empty\n");
	}
	else{
		for(i=0;i<heap_size;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
	}
	return 0;
}
