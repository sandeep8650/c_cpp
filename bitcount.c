/*******************************************
 * @author: Sandeep Singh
 * @date: Sat 23/Apr/2016 10:09:42 PM IST
 *
 *******************************************
 */
#include<stdio.h>

int bitcount(int x){
	int b;
	for(b=0;x!=0;x&=(x-1)){
		b++;
	}
	return b;
}

int main(){
	int x=-1;
	printf("bits in %d are %d\n",x,bitcount(x));
}
