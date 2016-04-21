int is_sorted(int A[],int start,int end){
	int i;
	for(i=start;i<end;i++){
		if(A[i]>A[i+1]){
			return 0;
		}
	}
	return 1;
}
