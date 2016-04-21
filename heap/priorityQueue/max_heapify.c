#include<stdio.h>
#include"priority_queue.h"

int max_heapify(int A[],int i,int heap_size){ //Array indexed with 0
		int left = (i<<1) + 1; // left = 2*i + 1
		int right = (i<<1) + 2; //right = 2*i + 2
		int largest;
		int temp;
		if((left <= heap_size-1) && (A[left]>A[i])){  //largest = index of max{A[i],leftof_A[i],rightof_A[i]}
			largest = left;
		}
		else{
			largest = i; 
		}
		if((right <= heap_size-1) && (A[right]>A[largest])){
			largest = right;
		}
		if(largest != i){ //if largest != i then swap A[i] and A[largest]
			temp = A[i];
			A[i] = A[largest];
			A[largest]  = temp;
			max_heapify(A,largest,heap_size); //max_hepify the swaped element A[largest]
		}
		return 0;
}
