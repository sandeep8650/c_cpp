//dictionary program(implement hashing)
//use: ./spell_hash [dictionary name]  [your file name]
 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

#define HASH_SIZE 16001 //prime

typedef struct node{
	char word[25];
	struct node *next;
}node;

#define NODE(name,w) \
	node *name=(node*)malloc(sizeof(node));strcpy(name->word,w);name->next=NULL

int check(char *fileName,int *totalText,int *misspell);
size_t hash(char *w);
int insert(char *w);
int load(char *fileName);
int search(char *w);
void unload();

node *HASH[HASH_SIZE];

int main(int argc, char *argv[]){
	int i=0;
	clock_t t1,t2,t3,t4;
	int misspell,totalWords,totalText;
	double t_load,t_check,t_unload,t_total;
	if(argc!=3){
		printf("Insufficient arguments\n");
		printf("USE: %s [dictionary name]  [your file name]",argv[0]);
		return 0;	
	}
	memset(HASH,0,HASH_SIZE);
	t1=clock();
	totalWords=load(argv[1]);
	t2=clock();
	check(argv[2],&totalText,&misspell);
	t3=clock();
	unload();
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
	FILE *disnry;
	char w[24];
	int word_count=0,i;
	disnry=fopen(fileName,"r");
	if(disnry==NULL){
		printf("Cannot open %s\n",fileName);
		exit(1);
	}
	while(fscanf(disnry,"%s",w)!=EOF){
		i=0;
		while(w[i]!='\0'){
			w[i]=tolower(w[i]);
			i++;
		}
		insert(w);
		word_count++;
	}
	fclose(disnry);
	printf("Load Successful\n");
	return word_count;
}

int search(char *w){
	size_t h=hash(w);
	node *ptr=HASH[h];
	while(ptr!=NULL && strcmp(ptr->word,w)){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		return 0;
	}
	else{
		return 1;
	}
}

size_t hash(char *w){
	size_t h=0,i=0;
	size_t v,x=1;
	while(w[i]!='\0'){
		v=(w[i]-'a')*x;
		h=(h+v)%HASH_SIZE;
		x=x*26;
		i++;
	}
	return h;
}

int insert(char *w){
	size_t h=hash(w);
	NODE(new,w);
	if(new==NULL){//if fail to allocate memory
		return -1;
	}
	node *ptr=HASH[h];
	if(HASH[h]==NULL){
		HASH[h]=new;
	}
	else{
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=new;
	}
	return 0;
}

int check(char *fileName,int *totalText,int *misspell){
	char w[25];
	*totalText=*misspell=0;
	FILE *file;
	file=fopen(fileName,"r");
	if(file==NULL){
		printf("Can not open file %s\n",fileName);
		unload();
		exit(1);
	}
	while(fscanf(file,"%s",w)!=EOF){
		if(search(w)==1){
			printf("+%s\n",w);
		}
		else{
			printf("-%s\n",w);
			(*misspell)++;
		}
		(*totalText)++;
	}
	fclose(file);
	return 0;
}

void unload(){
	int i;
	node *temp;
	for(i=0;i<HASH_SIZE;i++){
		while(HASH[i]!=NULL){
			temp=HASH[i];
			HASH[i]=HASH[i]->next;
			free(temp);
		}
	}
}
