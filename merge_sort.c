#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int arr[] = { 111, 121, 192, 5, 37, 154, 6, 150, 153, 171, 99, 171, 180, 42, 172, 7, 149, 197, 55, 87, 47, 142, 92, 163, 2, 99, 6, 65, 195, 130, 166, 95, 197, 26, 7, 11, 107, 186, 188, 17, 22, 181, 170, 160, 194, 171, 138, 44, 114, 77, 16, 50, 187, 17, 30, 54, 173, 132, 43, 180, 85, 151, 40, 60, 51, 8, 22, 48, 36, 44, 115, 4, 146, 76, 21, 24, 26, 159, 125, 199, 131, 196, 112, 35, 77, 126, 192, 88, 27, 16, 36, 31, 5, 117, 11, 26, 147, 40, 92};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}