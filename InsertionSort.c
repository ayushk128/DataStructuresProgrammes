#include <stdio.h>
void printArray(int *A, int n)
{
	int i;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
void insertionSort(int *A, int n){
    int key;
    int j;
    for(int i = 1; i<=n-1; i++){
        key = A[i];
        j = i-1;
        while(A[j] > key && j>=0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        printf("After pass %d the array is: ",i);
        printArray(A, n);
    }
}
int main()
{
	int A[] = {54, 12, 65, 7, 23, 9};
    int n = 6;
	printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
}