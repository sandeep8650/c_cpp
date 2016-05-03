/*******************************************
 * @author: Sandeep Singh
 * B.Tech CSE IIIyr ,FET GKV
 * @program to: implement DFS
 *******************************************
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2
#define V_SIZE 20
	
typedef struct node{
	int vertex;
	struct node *next;
}node;

#define NODE(name) \
	node *name
	
#define NODE_INIT(name,v) \
	name=(node*)malloc(sizeof(node));name->vertex=v;name->next=NULL

node *ADJ[V_SIZE]={NULL};
int color[V_SIZE]={white};
int parent[V_SIZE];
int d[V_SIZE];
int f[V_SIZE];
int time;

void scan_graph(int vertices){
	int n,nv;
	int i,j;
	node *new,*ptr;
	for(i=0;i<vertices;i++){
		printf("Enter no. of adjescent vertices of vertex %d: ",i);
		scanf("%d",&n);
		printf("Enter adjescent vertices of vertex %d: ",i);
		for(j=0;j<n;j++){
			scanf("%d",&nv);
			NODE_INIT(new,nv);
			if(ADJ[i]==NULL){
				ADJ[i]=new;
			}
			else{
				ptr=ADJ[i];
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=new;
			}
			new=NULL;
			ptr=NULL;
		}
		printf("\n");
	}
}

void free_graph(){
	int i=0;
	node *ptr;
	for(i=0;i<V_SIZE;i++){
		while(ADJ[i]!=NULL){
			ptr=ADJ[i];
			ADJ[i]=ADJ[i]->next;
			free(ptr);
		}
	}
}


void dfs_visit(int vertex){
	int i;
	node *ptr;
	time+=1;
	d[vertex]=time;
	color[vertex]=gray;
	ptr=ADJ[vertex];
	while(ptr!=NULL){
		if(color[ptr->vertex]==white){
			parent[ptr->vertex]=vertex;
			dfs_visit(ptr->vertex);
		}
		ptr=ptr->next;
	}
	color[vertex]=black;
	time+=1;
	f[vertex]=time;
}

void dfs(int vertices){
	int i;
	time=0;
	for(i=0;i<vertices;i++){
		if(color[i]==white){
			dfs_visit(i);
		}
	}
}

void print_path(int s,int v){
	if(s==v){
		printf("%d",s);
	}
	else if(parent[v]==-1){
		printf("No path from %d to %d exists\n",s,v);
	}
	else{
		print_path(s,parent[v]);
		printf("->%d",v);
	}	
}

int main(){
	int i,vertices,s;
	printf("Enter no. of vertices: ");
	scanf("%d",&vertices);
	scan_graph(vertices);
	printf("Enter source vertex:");
	scanf("%d",&s);
	dfs(vertices);
	printf("\n");
	for(i=0;i<vertices;i++){
		printf("path from source vertex %d to vertex %d: ",s,i);
		print_path(s,i);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<vertices;i++){
		printf("Discovery and Finish time of vertex %d: (%d,%d)",i,d[i],f[i]);
		printf("\n");
	}
	free_graph();
	return 0;
}
