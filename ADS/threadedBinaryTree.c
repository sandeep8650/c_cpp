/*******************************************************
 * @author: Sandeep Singh
 * B.Tech CSE IIIyr ,FET GKV
 * @program to: implement threaded binary tree
 *******************************************************
 */
 
#include<stdio.h>
#include<stdlib.h>

typedef struct node{ //structure of tree node
	struct node *llink;
	int ltag;
	int data;
	int rtag;
	struct node *rlink;
}tree_node;

/*macro for initialising empty tree
 *@name: name of tree head
 */
#define TREE_INIT(name) \
	tree_node name = { &(name), 1, 0, 0, &(name) }

/*macro for initialising new tree node
 *@name: name of tree node
 */ 	
#define TREE_NODE_INIT(name) \
	tree_node *name = (tree_node *)malloc(sizeof(tree_node))
	
/* function to insert data in tree_insert
 * @key: value of data to be insert
 * @head_ptr: pointer to head of tree
 */
int tree_insert(int key, tree_node *head_ptr){
	TREE_NODE_INIT(new); //initialising tree_node new
	if(new==NULL){ //return -1 if fail to initialize new node 
		return -1;
	}
	tree_node *ptr,*temp;
	new->data=key;
	new->ltag = new->rtag = 1;
	if(head_ptr->ltag==1){
		head_ptr->ltag=0;
		head_ptr->llink=new;
		
		new->llink = new->rlink = head_ptr;
	}
	else{
		ptr=head_ptr->llink;
		while(1){
			if(key <= ptr->data){	
				if(ptr->ltag==0){
					ptr = ptr->llink;
				}
				else if(ptr->ltag==1){
					break;
				}
			}
			else{
				if(ptr->rtag==0){
					ptr = ptr->rlink;
				}
				else{	//ptr->rtag==1
					break;
				}
			}
		}
		if(key <= ptr->data){
			ptr->ltag = 0;
			new->rlink = ptr;
			temp = ptr->llink;
			ptr->llink = new;
			new->llink = temp;
		}
		else{ //key > ptr->data
			ptr->rtag = 0;
			new->llink = ptr;
			temp = ptr->rlink;
			ptr->rlink = new;
			new->rlink = temp;
		}
	}
	return 0;
}

/* function to return pointer to inorder successor
 * @node_ptr: pointer to node of tree
 */
tree_node  *inorder_successor(tree_node *node_ptr){
	if(node_ptr->rtag==1){
		return node_ptr->rlink;
	}
	else{
		node_ptr=node_ptr->rlink;
		while(node_ptr->ltag!=1){
			node_ptr=node_ptr->llink;
		}
		return node_ptr;
	}
}

/* function to return pointer to preorder successor
 * @node_ptr: pointer to node of tree
 */
tree_node *preorder_successor(tree_node *node_ptr){
	if(node_ptr->ltag==0){
		return node_ptr->llink;
	}
	else{
		while(node_ptr->rtag==1){
			node_ptr = node_ptr->rlink;
		}
		return node_ptr->rlink;
	}
}

/* function for non recursive inorder traversal of tree
 * @head_ptr: pointer to head of tree
 */
void inorder_traverse(tree_node *head_ptr){
	tree_node *ptr = inorder_successor(head_ptr);
	while(ptr!=head_ptr){
		printf("%d, ",ptr->data);
		ptr = inorder_successor(ptr);
	}
}

/* function to return pointer to preorder successor
 * @head_ptr: pointer to head of tree
 */
void preorder_traverse(tree_node *head_ptr){
	tree_node *ptr = preorder_successor(head_ptr);
	while(ptr!=head_ptr){
		printf("%d, ",ptr->data);
		ptr = preorder_successor(ptr);
	}
}

/* recursive function for freeing all dynamically allocated memory
 * @root_ptr: pointer to root node of tree
 */
int free_tree(tree_node *root_ptr){
	if(root_ptr==root_ptr->llink){
		return 0;
	}
	if(root_ptr->ltag==0){
		free_tree(root_ptr->llink);
	}
	if(root_ptr->rtag==0){
		free_tree(root_ptr->rlink);
	}
	free(root_ptr);
}

int main(){
	TREE_INIT(HEAD);  //initialization of empty tree
	int c,key,r;
	while(1){
		printf("\n*********************************MENU******************************\n");
		printf("1. INSERT | 2. INORDER TRAVERSE | 3. PREORDER TRAVERSE | 4. EXIT\n: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter data: ");
				scanf("%d",&key);
				r=tree_insert(key,&HEAD);
				if(r==-1)printf("Could not allocate memory\n");
				break;
			case 2:
				inorder_traverse(&HEAD);
				break;
			case 3:
				preorder_traverse(&HEAD);
				break;
			case 4:
				free_tree(HEAD.llink); //passing address of root node
				HEAD.llink=&HEAD;
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;	
}

