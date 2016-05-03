#include<stdio.h>
void f(int **a,int **b){
	int *tmp;
	tmp=*a;*a=*b;*b=tmp;
}
int main(){
	int a=10,b=30;
	int *p1=&a,*p2=&b;
	printf("p1=%zu p2=%zu\n",p1,p2);
	f(&p1,&p2);
	printf("p1=%zu p2=%zu\n",p1,p2);
}
