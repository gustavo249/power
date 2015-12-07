#include <stdio.h>
#include <stdlib.h>

void    ft_merge(int *L, int *R, int *A, int lenL, int lenR)
{
    int i;
    int j;
    int k;

    // i - to mark the index of the left sub-array
    // j - to mark the index of the right sub-array
    // k - to mark the index of the original array

    i = 0; j = 0; k = 0;

    // comparing the values from the left and the right side and overwriting the original array
    while (i < lenL && j < lenR)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    // after sorting the left or right side into the original array, we check if for any remainder values in either splited sides
    
    while (i < lenL)
        A[k++] = L[i++]; // if so we put them after the sorted ones
    while (j < lenR)
        A[k++] = R[j++];
}

void    ft_mergesort(int *A, int size)
{
    int *left;
    int *right;
    int mid;
    int i;

    if (size < 2)
        return;

    mid = size / 2;
    // the elemends of the left sub-array go from (index 0 till mid - 1)
    // the elements of the righ one go from (size - mid till size - 1)
    if (!(left = (int*)malloc(sizeof(int) * mid)))
            left = NULL;
    if (!(right = (int*)malloc(sizeof(int) * (size - mid))))
        right = NULL;

    for (i = 0; i < mid; i++) // creating the left sub-array
        left[i] = A[i];
    for (i = mid; i < size; i++) // creating the right sub-array
        right[i - mid] = A[i];

    ft_mergesort(left, mid); // sorting the left sub-array
    ft_mergesort(right, size - mid); // sorting the right sub-array
    ft_merge(left, right, A, mid, size - mid); // merging them toghether into the original array
    free(left);
    free(right);
}

int main ()
{
    int A[] = { 3, 6, 5, 2, 1, 8, 7, 9, 4, 11 };
    int i;
    int len = sizeof(A) / sizeof(A[0]);

    ft_mergesort(A, len);
    for (i = 0; i < len; i++)
        printf("%d ", A[i]);
    printf("\n");
    return (0);
}
