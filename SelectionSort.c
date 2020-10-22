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
void selectionSort(int *A, int n)
{
    int indexOfMin;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
        printf("After pass %d:- ", i+1);
        printArray(A, n);
    }
}
int main()
{
    int A[] = {3, 5, 2, 12, 13};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
}