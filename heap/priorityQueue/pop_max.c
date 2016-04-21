#include<stdio.h>
#include"priority_queue.h"

int pop_max(int A[],int *heap_size){
	if(*heap_size<1){
		printf("Heap underflow\n");
		return 0;
	}
	int max = A[0];
	A[0]=A[*heap_size-1];
	*heap_size = *heap_size - 1;
	if(*heap_size){
		max_heapify(A,0,*heap_size); //adjusting A[0] element
	}
	return max;
}
