/* print all sub string
 */

#include<stdio.h>
#include<string.h>
#define SIZE 50
int main(){
	char str[SIZE];
	scanf("%s",str);
	int k=0,i=0,j=0,len=0;
	len= strlen(str);
	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			for(k=i;k<=j;k++){
				printf("%c",str[k]);
			}
			printf("\n");
		}
		//printf("\n");
	}
	
}
