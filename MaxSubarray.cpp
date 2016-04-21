#include<iostream>
#include<climits>

using namespace std;

void FMCS(int A[],int low,int high,int mid,int *cross_low,int *cross_high,int *cross_sum){
	int left_sum= INT_MIN;
	int right_sum=INT_MIN;
	int left_max;
	int right_max;
	int sum = 0;
	for(int i=mid;i>=low;i--){
		sum += A[i];
		if(sum>left_sum){
			left_sum=sum;
			left_max=i;
		}
	}
	sum = 0;
	for(int i=mid+1;i<=high;i++){
		sum += A[i];
		if(sum>right_sum){
			right_sum=sum;
			right_max=i;
		}
	}
	*cross_low = left_max;
	*cross_high = right_max;
	*cross_sum = left_sum+right_sum;
}

int FMS(int A[],int low,int high,int *l,int *h,int *s){
	 int mid = (low+high)/2;
	 int left_low,left_high,left_sum;
	 int right_low,right_high,right_sum;
	 int cross_low,cross_high,cross_sum;
	 if(high==low){
	 	*l = low;
	 	*h = high;
	 	*s = A[low];
	 	return 0;
	 }
	 FMS(A,low,mid,&left_low,&left_high,&left_sum);
	 FMS(A,mid+1,high,&right_low,&right_high,&right_sum);
	 FMCS(A,low,high,mid,&cross_low,&cross_high,&cross_sum);
	 if(left_sum>=cross_sum && left_sum>=right_sum){
	 	*l = left_low;
	 	*h = left_high;
	 	*s = left_sum;
	 	return 0;
	 }
	 if(right_sum>=cross_sum && right_sum>=left_sum){
	 	*l = right_low;
	 	*h = right_high;
	 	*s = right_sum;
	 	return 0;
	 }
	 else{
	 	*l = cross_low;
	 	*h = cross_high;
	 	*s = cross_sum;
	 	return 0;
	 }
}

int main(){
	int A[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int l,h,s;
	FMS(A,0,15,&l,&h,&s);
	cout<<"l,h,s : "<<l<<" "<<h<<" "<<s<<"\n";
	return 0;
}
