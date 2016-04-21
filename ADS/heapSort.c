/*******************************************
 * @author: Sandeep Singh
 * B.Tech CSE IIIyr ,FET GKV
 * @program to: sorting array using heapsort
 *******************************************
 */
#include<stdio.h>
#define SIZE 20

int heapsort(int A[],int heap_size){
	int temp;
	int i;
	build_max_heap(A,heap_size);
	for(i=heap_size-1;i>0;i--){
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		max_heapify(A,0,i);
	}
	return 0;
}

int max_heapify(int A[],int i,int heap_size){ //Array indexed with 0
		int left = (i<<1) + 1; // left = 2*i + 1
		int right = (i<<1) + 2; //right = 2*i + 2
		int largest;
		int temp;
		if((left <= heap_size-1) && (A[left]>A[i])){//largest=index of max{A[i],leftof_A[i],rightof_A[i]}
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

int build_max_heap(int A[],int heap_size){
	int i;
	i = (heap_size-2)>>1; /* i= index of parent of last element(heap_size-1)
							parent_of_A[i] = A[(i-1)/2] */
	while(i >= 0){
		max_heapify(A,i,heap_size);
		i--;
	}
	return 0;
}

void main(){
	int A[SIZE];
	int i,n;
	printf("Enter no. of keys: ");
	scanf("%d",&n);
	printf("Enter Array keys: ");
	for(i=0;i<n;i++){ scanf("%d",&A[i]); }
	heapsort(A,n);
	printf("Sorted array is: ");
	for(i=0;i<n;i++){ printf("%d ",A[i]); }
	printf("\n");
}
