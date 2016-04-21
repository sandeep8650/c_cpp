#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int i=0;
	srand(time(0));
	for(i=0;i<10000;i++){
		printf("%d\n",rand()%1000);
	}
}
