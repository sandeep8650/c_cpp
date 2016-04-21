/* reverse the string
 */

#include<stdio.h>
#include<string.h>
#define SIZE 50
int main(){
	char str[SIZE];
	char str2[SIZE];
	//scanf("%s",str);
	gets(str);
	int j=0,i=0;
	while(str[i]!='\0'){
		i++;
	}
	for(j=0;j<i;j++){
		str2[j]=str[i-j-1];
	}
	printf("%s\n",str2);
}
