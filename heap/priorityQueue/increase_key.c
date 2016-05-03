/*Return -1 if new key is less than current key */

#include<stdio.h>
#include"priority_queue.h"

#define parent(i) (i-1)>>2

int increase_key(int A[],int heap_size,int i,int key){
	int temp;
	if(i>=heap_size){
		printf("Node #%d does not exist in heap\n",i);
		return 0;
	}
	if(A[i]>key){
		printf("Value of new key is less than value of current key of node %d\n",i);
		return 0;
	}
	A[i]=key;
	while((i>0)&&(A[parent(i)]<A[i])){
		int temp = A[i];		/* swap value of A[i] and A[parent(i)]*/
		A[i] = A[parent(i)];
		A[parent(i)]=temp;
		i = parent(i);
	}
}
