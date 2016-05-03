/*******************************************
 * @author: Sandeep Singh
 * B.Tech CSE IIIyr ,FET GKV
 * @program to: implement BFS
 *******************************************
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2
#define Q_SIZE 20
#define V_SIZE 20

typedef struct queue{
	int data[Q_SIZE];
	int front;
	int rear;
}queue;

#define Q_INIT(name) \
	queue name;name.front=-1;name.rear=-1

#define Q_PUSH(name,v) \
	if(name.front>name.rear){name.front=name.rear=-1;} \
	if(name.rear==-1){name.front++;} \
	name.data[++name.rear]=v

#define Q_POP(name) \
	name.data[name.front++]
	
#define IS_Q_EMPTY(name) \
	(name.front==-1 || name.front>name.rear)
	
typedef struct node{
	int vertex;
	struct node *next;
}node;

#define NODE(name) \
	node *name
	
#define NODE_INIT(name,v) \
	name=(node*)malloc(sizeof(node));name->vertex=v;name->next=NULL

node *ADJ[V_SIZE]={NULL};
int parent[V_SIZE];

void scan_graph(int vertices){
	int n,nv;
	int i,j;
	node *new,*ptr;
	for(i=0;i<vertices;i++){
		printf("Enter no. of adjescent vertices of vertex %d:",i);
		scanf("%d",&n);
		printf("Enter adjescent vertices of vertex %d:",i);
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

void bfs(int s){
	int u;
	int color[V_SIZE]={white};
	memset(parent,-1,V_SIZE*sizeof(int));
	node *neighbour;
	Q_INIT(q);
	Q_PUSH(q,s);
	color[s]=gray;
	while(!IS_Q_EMPTY(q)){
		u=Q_POP(q);
		neighbour=ADJ[u];
		while(neighbour!=NULL){
			if(color[neighbour->vertex]==white){
				Q_PUSH(q,neighbour->vertex);
				color[neighbour->vertex]=gray;
				parent[neighbour->vertex]=u;
			}
			neighbour=neighbour->next;	
		}
		color[u]=black;
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
	bfs(s);
	printf("\n");
	for(i=0;i<vertices;i++){
		printf("path from source vertex %d to vertex %d: ",s,i);
		print_path(s,i);
		printf("\n");
	}
	free_graph();
	return 0;
}
