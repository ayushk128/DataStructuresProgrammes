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
void Merge(int *A, int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void MergeSort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, mid, low, high);
    }
}
int main()
{
    int A[] = {100, 90, 90, 70, 70};
    int n = 5;
    printArray(A, n);
    MergeSort(A, 0, 4);
    printArray(A, n);
}