#include<stdio.h>
#include"myheap.h"

int build_max_heap(int A[],size_t heap_size){
	size_t i;
	i = (heap_size-2)>>1; /* i= index of parent of last element(heap_size-1)
							parent_of_A[i] = A[(i-1)/2] */
	while(i > 0){
		max_heapify(A,i,heap_size);
		i--;
	}
	max_heapify(A,0,heap_size); // because i is type of size_t which is unsigned
	return 0;
}
