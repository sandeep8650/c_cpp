//Running time O( len(A)*len(B))

#include<cstdio>
#include<cstring>
#define SIZE 500

int bigMul(char A[],char B[],char C[]){
	int carry=0;
	int len_a=strlen(A);
	int len_b=strlen(B);
	int len_c=len_a + len_b;  //maximum length of result 
							  //can be sum of two length of operands
	//int i=len_a-1;
	//int j=len_b-1;
	int k=len_c-1;
	int res;
	memset(C,'0',len_c);
	C[k+1]='\0';
	for(int j=len_b-1;j>=0;j--){
		k = len_c-len_b+j;   //k = (len_c-1) - ((len_b-1)-j)
		carry=0;
		for(int i=len_a-1;i>=0;i--){
			res = (A[i]-'0')*(B[j]-'0') + (C[k]-'0') + carry ;
			C[k] = '0'+res%10;
			carry = res/10;
			k--;
			//printf("j=%d i=%d || res=%d C=%s carry=%d k=%d\n",j,i,res,C,carry,k);
		}
		C[k--]='0'+ carry;
	}
	return 0;
}

int main(int argc,char *A[]){
	char C[SIZE];
	if(argc==3){
		bigMul(A[1],A[2],C);
		printf("%s\n",C);
	}
	return 0;
}
