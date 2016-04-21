/* change lower case character
 * of string into upper case character
 */
#include<stdio.h>
#include<string.h>
#define SIZE 50
int main(){
	char str[SIZE];
	gets(str);
	int j=0,i=0,len;
	len=strlen(str);
	for(j=0;j<len;j++){
		if(str[j]>='a' && str[j]<='z'){
			printf("%c",str[j]+'A'-'a');
		}
		else{
			printf("%c",str[j]);
		}
	}
	printf("\n");
}
