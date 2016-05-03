#include<iostream>

using namespace std;
int x=5;
int main(){
	int x=10;
	{
	int x=15;
	cout<<x<<" "<<x<<"\n";
	}
	cout<<x<<" "<<::x<<"\n";
}
