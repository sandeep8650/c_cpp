#include<iostream>
using namespace std;
class Stack{
	private:
		int top;
		int size;
		int *stkptr;
	public:
		stack(){
			top = -1;
			size = 5;
			stkptr = new int[size];
		}
		stack(int sz){
			top = -1;
			size = sz;
			stkptr = new int[size];
		}
		bool isEmpty(){
			if(top==-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool isFull(){
			if(top==size-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool push(int v){
			if(!isFull()){
				stkptr[++top]=v;
				return true;
			}
			else{
				cout<<"Stack underflow\n";
				return false;
			}
		}
		int pop(){
			if(!isEmpty()){
				return stkptr[top--];
			}
			else{
				cout<<"Stack overflow\n";
				return -1;
			}
		}
		~stack(){
			delete[] stkptr;
		}
};
