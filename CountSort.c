#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void printArray(int *A, int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int max(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
void countSort(int A[], int n)
{
    int i;
    int j;
    int maxm = max(A, n);
    int *count = (int *)malloc(sizeof(maxm + 1));
    for (i = 0; i < maxm + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }
    i = 0;
    j = 0;
    while (i < maxm + 1)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
}