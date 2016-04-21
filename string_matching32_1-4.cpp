/* cormen question 32.1-4
 * incomplete code
 */
#include<iostream>
#include<cstring>

using namespace std;

int main(int argc,char *str[]){
	if(argc!=3){
    	cout<<"Error 1\n";
    	return 1;
    }
    int n = strlen(str[1]);
    int m = strlen(str[2]);
    int j=0,k = 0,flag=0;
    if(n<m){
    	cout<<"Error 2\n";
    	return 0;
    }
    for(int s=0;s<=n-m;s++){
        

    }
    if(flag==0){
        cout<<"Pattern does not occur\n";
    }
}
