#include<iostream>
using namespace std;

int Merge(int *A, int p, int q, int r)     
{
	int left, right, i, j, k; 
	left = q - p+1;
	right = r - q;             
	int L[left], R[right];
	
	for(i = 0; i < left; i++) L[i] = A[p+i];
	for(j = 0; j < right; j++) R[j] = A[q+j+1];
 
 	i=0, j=0;
	for(k=p; i<left && j<right; k++){
		if(L[i] < R[j]) A[k] = L[i++];	
		else A[k] = R[j++];
	}

	while(i < left) A[k++] = L[i++];
	while(j < right) A[k++] = R[j++];
}

int MergeSort(int A[], int p, int r)    
{
	int q;                                
	if(p < r){
		q = (p+r)/2;
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
	}
}

void imprimirArray(int arr[], int tam) {
    for (int i = 0; i < tam; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {9, 8, 2, 1, 6, 7, 5, 3, 4};
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: "; imprimirArray(arr, tam);
    MergeSort(arr, 0, tam - 1);
    cout << "Arreglo ordenado: "; imprimirArray(arr, tam);

    return 0;
}