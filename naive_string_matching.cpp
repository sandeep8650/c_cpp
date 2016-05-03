//uses: ./naive_string_matching [STRING] [PATTERN]
#include<iostream>
#include<cstring>
using namespace std;

int main(int argc,char *str[] ){
    if(argc!=3){
    	cout<<"Error 1\n";
    	return 1;
    }
    int n = strlen(str[1]);
    int m = strlen(str[2]);
    int k = 0,flag=0;
    if(n<m){
    	cout<<"Error 2\n";
    	return 0;
    }
    for(int s=0;s<=n-m;s++){
        k=0;
        while(k<m && str[2][k]==str[1][s+k]){
            k++;
        }
        if(k==m){
            cout<<"Pattern occurs with shift "<<s<<"\n";
            flag =1;
        }

    }
    if(flag==0){
        cout<<"Pattern does not occur\n";
    }
    return 0;
}
