# include <stdio.h>

int is_even(int number) {
  return number % 2 == 0;
}

void print_even_numbers(const int min, const int max) {
  for (int i = min; i <= max; i++) {
    if (is_even(i)) {
      printf("%d\n", i);
    }
  }
}

int main () {
  int min = 2;
  int max = 50;

  print_even_numbers(min, max);

  return 0;
}