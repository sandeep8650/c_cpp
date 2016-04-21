#include<cstdio>
void f(int &a,int &b){
	int tmp;
	tmp=a;a=b;b=tmp;
}
int main(){
	int a=10,b=30;
	printf("a=%d b=%d\n",a,b);
	f(a,b);
	printf("a=%d b=%d\n",a,b);
}
