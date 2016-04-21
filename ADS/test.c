#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}bst_node;
#define V_SIZE 10
int parent[V_SIZE];

int main(){
	int *c[10]={NULL},i;
	memset(parent,-,V_SIZE*sizeof(int));
	for(i=0;i<10;i++){
		printf("%d ",parent[i]);
	}
	return 0;
}
