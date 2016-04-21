#include<stdio.h>
#include"priority_queue.h"

int max(int A[],int heap_size){
	if(heap_size>0){
		return A[0];
	}
	printf("Heap is empty\n");
	return 0;
}
