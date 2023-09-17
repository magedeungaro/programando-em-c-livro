# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

int get_number() {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);
  
  return number;
}

int calculate_factorial(int number) {
  int result = 1;
  
  for (int i = 1; i <= number; i++) {
    result *= i;
  }
  
  return result;
}

int main() {
  int number = get_number();
  int factorial = calculate_factorial(number);
  printf("Factorial of %d is %d\n", number, factorial);
  return 0;
}