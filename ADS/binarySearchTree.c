/********************************************************************
 * @author: Sandeep Singh
 * B.Tech CSE IIIyr ,FET GKV
 * @program to: recursive and non-recursive traversal of binarytree
 ********************************************************************
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{ //structure of tree node
	struct node *left;
	int data;
	struct node *right;
}bst_node;

#define SIZE 100 //max size of stack

typedef struct stack{ //structure of stack
	bst_node *data[SIZE];
	int top;
}stack;

/* macro for declaration and initialising stack
 * name: name of stack;
 */
#define STACK_INIT(name) \
	stack name; name.top=-1

/* macro to push data in stack
 * @name: name of stack;
 * @pointer: pointer of type bst_node to be push
 */
#define PUSH(name, pointer) \
	name.data[++name.top]=pointer

/* macro to pop stack
 * @name: name of stack;
 */
#define POP(name) \
	name.data[name.top--]

/* macro access top data of stack
 * @name: name of stack;
 */
#define TOP(name) \
	name.data[name.top]

/* macro to check whether stack is empty or not
 * @name: name of stack;
 */	
#define IS_STACK_EMPTY(name) \
	(name.top==-1)

/* macro to initialise empty binary tree
 * @name: name of tree;
 */
#define BST_INIT(name) \
	bst_node *name = NULL

/* macro to declare node and allocate memory for node
 * @name: name of node;
 */
#define BST_NODE(name) \
	bst_node *name = (bst_node*)malloc(sizeof(bst_node))

/* macro to initialise tree node
 * @name: name of node;
 */
#define BST_NODE_INIT(name,left_value,data_value,right_value) \
	name->data=data_value; name->left=left_value; name->right=right_value


/* insert key in tree
 * @key: value of data to be insert
 * @root_ptr: pointer to ROOT pointer
 */
int	insert(int key, bst_node **root_ptr){
	bst_node *temp;
	BST_NODE(new); //allocate memory for new node
	if(new==NULL){ //return -1 if fail to initialize new node
		return -1; 
	}
	BST_NODE_INIT(new,NULL,key,NULL); //initialising new node with data=key
	if(*root_ptr==NULL){ //if tree is empty
		*root_ptr=new;
	}
	else{
		temp=*root_ptr;
		while(1){
			if(key <= temp->data){
				if(temp->left == NULL){
					break;
				}
				else{
					temp=temp->left;
				}
			}
			else{//key>temp->data
				if(temp->right==NULL){
					break;
				}
				else{
					temp=temp->right;
				}
			}
		}
		if(key <= temp->data){
			temp->left=new;
		}
		else{
			temp->right=new;
		}
	}
	return 0;
}

/* recursive function for inorder traversal of BST
 * @ptr: ROOT pointer
 */
void recursive_inorder_traverse(bst_node *ptr){
	if(ptr==NULL){ return; }
	recursive_inorder_traverse(ptr->left);
	printf("%d,",ptr->data);
	recursive_inorder_traverse(ptr->right);
}

/* recursive function for preorder traversal of BST
 * @ptr: ROOT pointer
 */
void recursive_preorder_traverse(bst_node *ptr){
	if(ptr==NULL){ return; }
	printf("%d,",ptr->data);
	recursive_preorder_traverse(ptr->left);
	recursive_preorder_traverse(ptr->right);
}

/* recursive function for postorder traversal of BST
 * @ptr: ROOT pointer
 */
void recursive_postorder_traverse(bst_node *ptr){
	if(ptr==NULL){ return; }
	recursive_postorder_traverse(ptr->left);
	recursive_postorder_traverse(ptr->right);
	printf("%d,",ptr->data);
}

/* non-recursive function for inorder traversal of BST
 * @ptr: ROOT pointer
 */
void iterative_inorder_traverse(bst_node *ptr){
	STACK_INIT(stk);
	while(!IS_STACK_EMPTY(stk) || ptr!=NULL ){
		while(ptr!=NULL){
			PUSH(stk,ptr);
			ptr=ptr->left;
		}
		ptr = POP(stk);
		printf("%d,",ptr->data);
		ptr=ptr->right;
	}
}

/* non-recursive function for preorder traversal of BST
 * @ptr: ROOT pointer
 */
void iterative_preorder_traverse(bst_node *ptr){
	if(ptr==NULL){ return; }
	STACK_INIT(stk);
	PUSH(stk,ptr);
	while( !IS_STACK_EMPTY(stk) ){
		ptr = POP(stk);
		printf("%d,",ptr->data);
		if(ptr->right != NULL){
			PUSH(stk,ptr->right);
		}
		if(ptr->left != NULL){
			PUSH(stk,ptr->left);
		}
	}
}

/* non-recursive function for postorder traversal of BST
 * @ptr: ROOT pointer
 */
void iterative_postorder_traverse(bst_node *ptr){
	if(ptr==NULL) return;
	bst_node *prev=ptr;
	STACK_INIT(stk);
	PUSH(stk,ptr);
	while( !IS_STACK_EMPTY(stk) ){
		ptr=TOP(stk);
		if( (prev == ptr->right) || (prev == ptr->left) || ((ptr->right==NULL)&&(ptr->left==NULL)) ){
			prev=POP(stk);
			printf("%d,",prev->data);
		}
		else{
			if(ptr->right != NULL){
				PUSH(stk,ptr->right);
			}
			if(ptr->left != NULL){
				PUSH(stk,ptr->left);
			}
		}
	}
}
/* recursive function to free allocated heap memory
 * @ptr: ROOT pointer
 */
void free_tree(bst_node *ptr){
	if(ptr==NULL){ return; }
	free_tree(ptr->left);
	free_tree(ptr->right);
	free(ptr);
}

int main(){
	int c,key,r;
	BST_INIT(ROOT);
	while(1){
		printf("\n************************MENU**********************\n");
		printf("1.Insert|2.NonRecInorder|3.RecInorder|4.NonRecPreorder|5.RecPreorder|6.NonRecPostorder|7.RecPostorder|8.Exit\n: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter data: ");
				scanf("%d",&key);
				r=insert(key,&ROOT);
				if(r==-1)printf("Could not allocate memory\n");
				break;
			case 2:
				printf("NonRecInorder: ");
				iterative_inorder_traverse(ROOT);
				break;
			case 3:
				printf("RecInorder: ");
				recursive_inorder_traverse(ROOT);
				break;
			case 4:
				printf("NonRecPreorder: ");
				iterative_preorder_traverse(ROOT);
				break;
			case 5:
				printf("RecPreorder: ");
				recursive_preorder_traverse(ROOT);
				break;
			case 6:
				printf("NonRecPostorder: ");
				iterative_postorder_traverse(ROOT);
				break;
			case 7:
				printf("RecPostorder: ");
				recursive_postorder_traverse(ROOT);
				break;
			case 8:
				free_tree(ROOT);
				exit(0);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
