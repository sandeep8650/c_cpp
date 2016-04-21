#include<iostream>
#include"stack.cpp"
using namespace std;

int main(){
	stack stk = stack();
	int i=0;
	while(stk.isFull()==false){
		stk.push(i++);
	}
	stk.push(10);
	while(stk.isEmpty()==false){
		cout<<stk.pop()<<endl;
	}
	return 0;
}
