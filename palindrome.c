#include<stdio.h>
#include<string.h>

int main(int argc,char *str[]){
	if(argc!=2){
		printf("Use: ./palindrome [string]\n");
		return 0;
	}
	size_t length = strlen(str[1]);
	size_t i=0;
	while(str[1][i]==str[1][length-1-i] && i<length/2){
		i++;
	}
	i==(length/2)?printf("Palindrome\n"):printf("Not palindrome\n");
	return 0;
}
