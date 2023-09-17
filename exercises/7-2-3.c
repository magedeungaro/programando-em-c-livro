# include <stdio.h>
# include <stdlib.h>

int get_integer() {
  int number;
  printf("Enter an integer: ");
  scanf("%d", &number);

  return number;
}

void print_multiplication_table(const int integer, const int limit) {
  for (int i = 1; i <= limit; i++) {
    printf("%d x %d = %d\n", integer, i, integer * i);
  }
}

int main () {
  int integer = get_integer();
  int limit = 10;
  print_multiplication_table(integer, limit);

  return 0;
}