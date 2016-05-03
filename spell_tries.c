//dictionary program(implement tries data structure)
//use: ./spell_tries [dictionary name]  [your file name]
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

typedef struct node{
	int is_word;
	struct node *child[27];
}node;
node *root = NULL;

void insert(char *key);
int search(char *key);
int load(char *fileName);
int check(char *fileName,int *totalText,int *misspell);
void unload(node **ptr);

int main(int argc, char *argv[]){
	clock_t t1,t2,t3,t4;
	int misspell,totalWords,totalText;
	double t_load,t_check,t_unload,t_total;
	if(argc!=3){
		printf("Insufficient arguments\n");
		printf("USE: %s [dictionary name]  [your file name]",argv[0]);
		return 0;	
	}
	t1=clock();
	totalWords=load(argv[1]);
	t2=clock();
	check(argv[2],&totalText,&misspell);
	t3=clock();
	unload(&root);
	t4=clock();
	t_load= (double)(t2-t1)/CLOCKS_PER_SEC;
	t_check= (double)(t3-t2)/CLOCKS_PER_SEC;
	t_unload= (double)(t4-t3)/CLOCKS_PER_SEC;
	t_total= (double)(t4-t1)/CLOCKS_PER_SEC;
	printf("Total no. of words in %s: %d\n",argv[1],totalWords);
	printf("Total no. of words in %s: %d\n",argv[2],totalText);
	printf("Total no. of misspelled words in %s: %d\n",argv[1],misspell);
	printf("time taken by load(): %lf\n",t_load);
	printf("time taken by check(): %lf\n",t_check);
	printf("time taken by unload(): %lf\n",t_unload);
	printf("total time: %lf\n",t_total);
	return 0;
}

int load(char *fileName){
	int i=0;
	char word[10];
	FILE *disnry;
	disnry = fopen(fileName,"r");
	if(disnry==NULL){
		printf("Cannot open %s\n",fileName);
		exit(1);
	}
	while(fscanf(disnry,"%s",word)!=EOF){
		insert(word);
		i++;
	}
	fclose(disnry);
	printf("Load Successful\n");
	return i; //return total number of loaded words
}

int check(char *fileName,int *totalText,int *misspell){
	char word[50];
	int i=0,j=0;
	FILE *f;
	f = fopen(fileName,"r");
	if(f==NULL){
		printf("Cannot open %s\n",fileName);
		unload(&root);
		exit(2);
	}
	while(fscanf(f,"%s",word)!=EOF){
		if(!search(word)){
			i++;
			printf("-%s\n",word);
			//printf("Not Found\n");
		}
		else{
			//j++;
			printf("+%s\n",word);
			//printf("Found\n");
		}
		j++;
	}
	fclose(f);
	*misspell=i;
	*totalText=j;
	return 0;
}


void insert(char *key){
	int i=0;
	char k;
	node *new;
	if(root==NULL){
		new=(node*)calloc(1,sizeof(node)); //allocate memory and initialise to zero
		root=new;
	}
	node *t=root;
	while(key[i] != '\0'){
		k=tolower(key[i]);
		if((t->child[k-'a']) == NULL){
			new=(node*)calloc(1,sizeof(node)); //allocate memory and initialise to zero
			t->child[k-'a'] = new;
		}
		
		t = t->child[k-'a'];
		i++;
	}
	t->is_word = 1;
}

int search(char *key){
	int i=0;
	char k;
	node *t=root;
	if(root==NULL){
		return 0;
	}
	while(key[i]!= '\0'){
		k=tolower(key[i]);
		if((t->child[k-'a']) ==NULL){
			return 0;
		}
		else{
			t = t->child[k-'a'];
		
		}
		i++;
	}
	if((t->is_word) == 0){
		return 0;
	}
	else{
		return 1;
	}
}

void unload(node **ptr){
	int i=0;
	if(*ptr==NULL){ return; }
	for(i=0;i<27;i++){
		unload(&((*ptr)->child[i]));
	}
	free(*ptr);
	*ptr=NULL;
}
