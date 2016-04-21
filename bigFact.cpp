#include<cstdio>
#include<cstdlib>
#include<cstring>


#define max(a,b) (a>b?a:b)
#define SIZE 10000


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

int bigFact(int n,char F[]){
	char N[SIZE]="1";
	strcpy(F,"1");
	char temp[SIZE];
	char *ptr;
	char one[]="1";
	for(int i=0;i<n;i++){
		//printf("F=%s\nN=%s\n----\n",F,N);
		bigMul(F,N,temp);
		ptr=temp;
		while((*ptr)=='0'){
			ptr++;
		}
		strcpy(F,ptr);
		bigAdd(N,one,temp);
		ptr=temp;
		while((*ptr)=='0'){
			ptr++;
		}
		strcpy(N,ptr);
	}
	return 0;
}

int main(int argc,char *argv[]){
	int n = atoi(argv[1]);
	char F[SIZE];
	bigFact(n,F);
	printf("%s\n",F);
	return 0;
}






