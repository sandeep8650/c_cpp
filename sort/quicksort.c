int quicksort(int A[],int start,int end){
	int i=start-1,j,temp;
	int x = A[end];
	if(start<end){
		for(j=start;j<end;j++){
			if(A[j]<=x){
				i++;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		i++;
		temp = A[i];
		A[i] = A[end];
		A[end] = temp;
		quicksort(A,start,i-1);
		quicksort(A,i+1,end);
	}
	return 0;
}

