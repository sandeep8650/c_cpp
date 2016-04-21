#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char str[100];
	int i=0,j,n=0;
	scanf("%s",str);
	int len = strlen(str);
	while(i<len){
		if(str[i]=='\\'){
			printf("%d ",n);
			n=0;
			j=64;
			
		}
		else{
			n = n + ((int)str[i] - 48)*(j);
			j=j>>3;
		}
		 i++;
		 if(i==len){
		 	printf("%d\n",n);
		 }
	}	
	return 0;
}
