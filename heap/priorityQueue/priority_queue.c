#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"priority_queue.h"

#define SIZE 10

int main(){
	int c,key,i;
	int A[SIZE]={INT_MIN};
	int heapsize=0;
	while(1){
		printf("*************MENU**************\n");
		printf("1. Insert key\n2. Increase key\n3. Max key\n4. Pop max key\n5. Show Heap\n6. Exit\n: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				if(heapsize<SIZE){
					printf("Enter key: ");
					scanf("%d",&key);
					insert(A,&heapsize,key);
				}
				else{
					printf("Heap overflow\n");
				}
				break;
			case 2:
				printf("Enter position and new key: ");
				scanf("%d%d",&i,&key);
				increase_key(A,heapsize,i,key);
				break;
			case 3:
				printf("Maximum key in Heap is: %d\n",max(A,heapsize));
				break;
			case 4:
				printf("Maximum key in heap is: %d\n",pop_max(A,&heapsize));
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
