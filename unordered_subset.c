#include<stdio.h>
#define SIZE 20
int main(){
	int a[SIZE];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				printf("%d",a[j]);
			}
		}
		printf("\n");
	}
}
