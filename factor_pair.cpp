/* It print all pair of factors
 * of number including 1.
 * complexity O( sqrt(n) )
 */
#include<cstdio>
#include<cmath>

int main(){
	int n,j;
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++){
		j=n/i;
		if(n==i*j){
			printf("[%d,%d]\n",i,j);
		}
	}
	return 0;
}
