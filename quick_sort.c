#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() {
  int data[] = { 111, 121, 192, 5, 37, 154, 6, 150, 153, 171, 99, 171, 180, 42, 172, 7, 149, 197, 55, 87, 47, 142, 92, 163, 2, 99, 6, 65, 195, 130, 166, 95, 197, 26, 7, 11, 107, 186, 188, 17, 22, 181, 170, 160, 194, 171, 138, 44, 114, 77, 16, 50, 187, 17, 30, 54, 173, 132, 43, 180, 85, 151, 40, 60, 51, 8, 22, 48, 36, 44, 115, 4, 146, 76, 21, 24, 26, 159, 125, 199, 131, 196, 112, 35, 77, 126, 192, 88, 27, 16, 36, 31, 5, 117, 11, 26, 147, 40, 92};
  int n = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, n - 1);
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}