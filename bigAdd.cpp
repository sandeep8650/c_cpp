//Running time O( max(len(A),len(B)) )

#include<cstdio>
#include<cstring>

#define SIZE 50
#define max(a,b) (a>b?a:b)

int bigAdd(char A[],char B[],char C[]){
	int carry=0;
	int len_a=strlen(A);
	int len_b=strlen(B);
	int len_c=max(len_a,len_b) + 1;
	int i=len_a-1;
	int j=len_b-1;
	int k=len_c;
	int sum;
	C[k--]='\0';
	while((i>=0)&&(j>=0)){
		sum = (A[i--]-'0') + (B[j--]-'0') + carry;
		C[k--]='0'+ sum%10;
		carry = sum/10;
	}
	if(i<0){
		while(j>=0){
			sum = (B[j--]-'0') + carry;
			C[k--] = '0' + sum%10;
			carry = sum/10;
		}
	}
	else if(j<0){
		while(i>=0){
			sum = (A[i--]-'0') + carry;
			C[k--] = '0' + sum%10;
			carry = sum/10;
		}
	}
	C[k--]='0'+carry;
	return 0;
}

int main(int argc,char *A[]){
	char C[SIZE];
	bigAdd(A[1],A[2],C);
	printf("%s\n",C);
	return 0;
}
