#include<stdio.h>
#define SIZE 5
int check(int mat[SIZE][SIZE]){
	int i=0,j=0;
	int sum1=0,sum2=0,sum3;
	for(i=0;i<SIZE;i++){
		sum2=0;
		for(j=0;j<SIZE;j++){
			sum2 += mat[i][j];
		}
		//printf("sum2=%d\n",sum2);
		if((sum2!=sum1) && (sum1!=0)){
			printf("row\n");
			return 0;
		}
		else{
			sum1=sum2;
		}
	}
	for(i=0;i<SIZE;i++){
		sum2=0;
		for(j=0;j<SIZE;j++){
			sum2 += mat[j][i];
		}
		if((sum2!=sum1) && (sum1!=0)){
			printf("col\n");
			return 0;
		}
		else{
			sum1=sum2;
		}
	}
	sum2=0;
	sum3=0;
	for(i=0;i<SIZE;i++){
		sum2 += mat[i][i];
		sum3 += mat[i][SIZE-i-1];
	}
	if((sum3!=sum1) || (sum2!=sum1)){
		printf("d1!=d2\n");
		return 0;
	}
	return 1;
}

int main(){
	int mat[SIZE][SIZE]={{1,1,1,1,1},
				 		 {1,1,1,1,1},
				  		 {1,1,1,1,1},
				 		 {1,1,1,1,1},
				 		 {1,1,1,1,1},
						};
	int i=0,j=0,k;
	k=check(mat);
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	if(k==0){
		printf("Not magic matrix\n");
	}
	else{
		printf("Magic matrix\n");
	}
	return 0;
}
