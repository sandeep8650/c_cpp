/****************************************************
 * @author: Sandeep Singh
 * B.Tech CSE IIIyr ,FET GKV
 * @program to: implement priority queue using array
 ****************************************************
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 50
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

int pop_max(int A[],int *heap_size){
	if(*heap_size<1){
		printf("Priority queue underflow\n");
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

int max(int A[],int heap_size){
	if(heap_size>0){
		return A[0];
	}
	printf("Priority queue is empty\n");
	return 0;
}

int print_heap(int A[],int heap_size){
	int i=0;
	if(heap_size<1){
		printf("Priority queue is empty\n");
	}
	else{
		for(i=0;i<heap_size;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
	}
	return 0;
}

int increase_key(int A[],int heap_size,int i,int key){
	int temp;
	if(i>=heap_size){
		printf("Node #%d does not exist in priority queue\n",i);
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


int main(){
	int c,key,i;
	int A[SIZE]={INT_MIN};
	int heapsize=0;
	while(1){
		printf("\n***************************************MENU******************************************************\n");
		printf("1. Insert key | 2. Increase key | 3. Max key | 4. Pop max key | 5. Show priority queue | 6. Exit\n: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				if(heapsize<SIZE){
					printf("Enter key: ");
					scanf("%d",&key);
					insert(A,&heapsize,key);
				}
				else{
					printf("Priority queue overflow\n");
				}
				break;
			case 2:
				printf("Enter position and new key: ");
				scanf("%d%d",&i,&key);
				increase_key(A,heapsize,i,key);
				break;
			case 3:
				printf("Maximum key in priority queue is: %d\n",max(A,heapsize));
				break;
			case 4:
				printf("Poped key is: %d\n",pop_max(A,&heapsize));
				break;
			case 5:
				print_heap(A,heapsize);
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("Incorrect choice\n");
		}
	}
	return 0;
}

