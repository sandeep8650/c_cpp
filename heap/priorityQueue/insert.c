#include<stdio.h>
#include"priority_queue.h"

#define parent(i) (i-1)>>1

void insert(int A[],int *heap_size,int key){
	int temp;
	int i;
	(*heap_size)++;
	A[(*heap_size)-1]=key;
	i=(*heap_size)-1;
	while((i>0)&&(A[parent(i)]<A[i])){
		temp = A[i];		/* swap value of A[i] and A[parent(i)]*/
		A[i] = A[parent(i)];
		A[parent(i)]=temp;
		i = parent(i);
	}
}
