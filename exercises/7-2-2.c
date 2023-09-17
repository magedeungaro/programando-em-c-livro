# include <stdio.h>
# include <stdlib.h>

int array_sum(int* array, const int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
  }

  return sum;
}

int* generate_array(const int min, const int length) {
  int* array = malloc(sizeof(int) * length);

  for (int i = 0; i < length; i++) {
    array[i] = i + min;
  }

  return array;
}

int main () {
  int initial_value = 1;
  int length = 100;
  int* array = generate_array(initial_value, length);
  int sum = array_sum(array, length);
  printf("Total sum is %d\n", sum);
  free(array);
  return 0;
}