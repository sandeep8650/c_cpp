#include<stdio.h>
#include"myheap.h"

int heapsort(int A[],size_t heap_size){
	int temp;
	size_t i;
	build_max_heap(A,heap_size);
	for(i=heap_size-1;i>0;i--){
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		max_heapify(A,0,i);
	}
	return 0;
}
