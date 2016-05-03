//Incomplete code

#include<iostream>
#include<cstring>



using namespace std;

int main(int argc,char *str[]){
	if(argc!=3){
    	cout<<"Error 1\n";
    	return 1;
    }
    int d=256;
	int q=256;
    int m= strlen(str[2]);
    int n= strlen(str[1]);
    int h= 1;
    size_t p=0;
    int k=0;
    size_t *t = new size_t[n-m+1];
    t[0] = 0;
    for(int i=1;i<m;i++){  //calculate h
    	h = (h*d)%q;
    }
    //cout<<h<<"\n";
    for(int i=0;i<m;i++){ //calculate p and t[0]
    	p = (d*p + size_t(str[2][i]))%q;
    	t[0] = (d*t[0] + size_t(str[1][i]))%q;
    }
    //cout<<"p and t0 ="<<p<<" "<<t[0]<<"\n"; 
    for(int s=0;s<=n-m;s++){
    	if(t[s]==p){
    		k=0;
    		while(str[1][s+k]==str[2][k] && k<m){
    			k++;
    		}
    		if(k==m){cout<<"Pattern occurs with shift "<<s<<"\n";}
    	}
    	if(s<n-m){
    		t[s+1] = (d*(t[s]-(size_t(str[1][s])*h)%q) + str[1][s+m])%q;
    		//cout<<t[s+1]<<"\n";
    	}
    }
    delete []t;
	
}
