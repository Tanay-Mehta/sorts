#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void print(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void Sort(int arr[], int size)
{
    int i,j,min_num;
    for (i=0;i<size-1;i++)
    {
        min_num = i;
        for (j = i+1; j < size; j++)
          if (arr[j] < arr[min_num])
            min_num = j;
        swap(&arr[min_num], &arr[i]);
    }
}
int main()
{
    int arr[] = {111, 121, 192, 5, 37, 154, 6, 150, 153, 171, 99, 171, 180, 42, 172, 7, 149, 197, 55, 87, 47, 142, 92, 163, 2, 99, 6, 65, 195, 130, 166, 95, 197, 26, 7, 11, 107, 186, 188, 17, 22, 181, 170, 160, 194, 171, 138, 44, 114, 77, 16, 50, 187, 17, 30, 54, 173, 132, 43, 180, 85, 151, 40, 60, 51, 8, 22, 48, 36, 44, 115, 4, 146, 76, 21, 24, 26, 159, 125, 199, 131, 196, 112, 35, 77, 126, 192, 88, 27, 16, 36, 31, 5, 117, 11, 26, 147, 40, 92};
    int n = sizeof(arr)/sizeof(arr[0]);
    Sort(arr, n);
    printf("Sorted array: \n");
    print(arr, n);
    return 0;
}