#include<stdio.h>

int minmax(int A[],int size,int *min, int *max){
	int i;
	if(size%2!=0){
		*min=*max=A[0];
		for(i=1;i<size-1;i+=2){
			if(A[i]>A[i+1]){
				if(A[i]>(*max)){
					*max=A[i];
				}
				if(A[i+1]<(*min)){
					*min=A[i+1];
				}
			}
			else{
				if(A[i+1]>(*max)){
					*max=A[i+1];
				}
				if(A[i]<(*min)){
					*min=A[i];
				}
			}
		}
	}
	else{
		if(A[0]>A[1]){
			*max=A[0];
			*min=A[1];
		}
		else{
			*max=A[1];
			*min=A[0];
		}
		for(i=2;i<size-1;i+=2){
			if(A[i]>A[i+1]){
				if(A[i]>(*max)){
					*max=A[i];
				}
				if(A[i+1]<(*min)){
					*min=A[i+1];
				}
			}
			else{
				if(A[i+1]>(*max)){
					*max=A[i+1];
				}
				if(A[i]<(*min)){
					*min=A[i];
				}
			}
		}
	}
}

int main(){
	int A[]={5,4,3,2,1,6,7,8,9,100,-1};
	int min,max;
	minmax(A,11,&min,&max);
	printf("min=%d\nmax=%d\n",min,max);
	return 0;
}
