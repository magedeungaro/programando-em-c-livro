#include <stdio.h>

// Observation: Since there will be always 3 numbers to be sorted
// it would be simpler just to use bubble sort

void bubbleSort(int array[], int length) {
  int i, j, temp;
  
  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int get_number() {
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);
  return number;
}

void print_array(int array[], int length) {
  printf("Sorted array: ");

  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

int main() {
  int arr[] = { get_number(), get_number(), get_number() };
  int length = 3;
  bubbleSort(arr, 3);
  print_array(arr, 3);

  return 0;
}