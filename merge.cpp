#include <iostream>
using namespace std;

void merge(int A[],int L[],int Ln,int R[],int Rn){
	int i=0,j=0,index=0;
	
	while(i<Ln && j<Rn){
		if(L[i] < R[j]) A[index] = L[i++];
		else A[index] = R[j++];
		index++;
	}
	
	while(i<Ln) A[index++] = L[i++];
	while(j<Rn) A[index++] = R[j++];
}



void mergeSort(int A[],int n){

	if(n<2) return;
	
	int Ln = (n/2), Rn = (n-(n/2));
	int L[Ln],R[Rn],i;
	
	for(i=0;i<Ln;i++) {
		L[i] = A[i];
	}
	
	for(i=Ln;i<n;i++){
	 	R[i-Ln] = A[i];
	}
	
	mergeSort(L,Ln);
	mergeSort(R,Rn);
	merge(A,L,Ln,R,Rn);
}


int main(){
	int array[] = {78,24,56,14,2,89,67,94,10,4,47,86};	
	mergeSort(array,12);

	int i ;
	for(i=0;i<12;i++){
		cout << array[i]<<" ";
	}
	cout << endl;	
	
	return 0;
}

