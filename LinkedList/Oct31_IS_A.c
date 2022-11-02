// Insertion sort on Array, Source Link: https://www.programiz.com/dsa/insertion-sort

#include <stdio.h>

// Printing an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionSort(int arr[], int size) {
  for (int step = 1; step < size; step++) {
    int key = arr[step];
    int j = step - 1;

    
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

// Driver code
int main() {
  int d[] = {8, 6, 3, 4, 7};
  int size = sizeof(d) / sizeof(d[0]);
  insertionSort(d, size);
  printf("Sorted array in ascending order:\n");
  printArray(d, size);
}