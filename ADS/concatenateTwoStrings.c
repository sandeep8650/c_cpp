/******************************************************************
 * @author: Sandeep Singh
 * B.Tech CSE IIIyr ,FET GKV
 * @program to: Concatenate two strings and calculate its length.
 ******************************************************************
 */

#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
int main(){
	char str1[MAX_SIZE],str2[MAX_SIZE],str3[2*MAX_SIZE];
	int len1=0,len2=0,len3=0;
	printf("Enter first string(max length %d): ",MAX_SIZE-1);
	scanf("%s",str1);
	printf("Enter second string(max length %d): ",MAX_SIZE-1);
	scanf("%s",str2);
	while(str1[len1]!='\0'){
		len1++;
	}
	while(str2[len2]!='\0'){
		len2++;
	}
	while(len3<len1){
		str3[len3]=str1[len3];
		len3++;
	}
	while(len3<len1+len2){
		str3[len3]=str2[len3-len1];
		len3++;
	}
	str3[len3]='\0';
	printf("%s + %s = %s\n",str1,str2,str3);
	printf("Length of concatenated string is %d\n",len3);
	return 0;
}
