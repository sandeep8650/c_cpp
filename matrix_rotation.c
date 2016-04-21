#include<stdio.h>

#define SIZE 6

int main(){
	int M[SIZE][SIZE],temp;
	int S;
	scanf("%d",&S);
	for(int i=0;i<S;i++)
		for(int j=0;j<S;j++)
			scanf("%d",&M[i][j]);
	for(int i=0;i<=(S-1)/2;i++){
		for(int j=i;j<(S-1-i);j++){
			temp=M[i][j];
			M[i][j]			=	M[S-1-j][i];
			M[S-1-j][i]		=	M[S-1-i][S-1-j];
			M[S-1-i][S-1-j]	=	M[j][S-1-i];
			M[j][S-1-i]		=	temp;
		}
	}
	for(int i=0;i<S;i++){
		for(int j=0;j<S;j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
	return 0;
}
