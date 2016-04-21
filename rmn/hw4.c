#include<stdio.h>
void strcp(char a[],char b[]){
	int i=0,len=0;
	while(a[len]!='\0'){
		len++;
	}
	while(i<len){
		b[i]=a[i];
		i++;
	}
	b[i]='\0';
}

void strcp3(char a[],char b[],char c[]){
	int i=0,len=0;
	while(a[len]!='\0'){
		len++;
	}
	while(i<len){
		b[i]=a[i];
		c[i]=a[i];
		i++;
	}
	b[i]='\0';
	c[i]='\0';
}

int main(){
	char a[]="sandeep",b[]="bbbbbbbbbbbbbbb",c[]="ccccccccccccccc";
	printf("a=%s b=%s c=%s\n",a,b,c);
	strcp3(a,b,c);
	printf("a=%s b=%s c=%s\n",a,b,c);
}
