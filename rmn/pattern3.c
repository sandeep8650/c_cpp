#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
	int n=11;
	int i=0,j;
	int m=n/2;
	//while(1){
	for(i=0;i<m+1;i++){
		for(j=0;j<n;j++){
			if(j>=m-i && j<=m+i){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	//}
	return 0;	
}
