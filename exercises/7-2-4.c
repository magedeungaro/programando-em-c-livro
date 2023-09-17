# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

float get_number(char* prompt) {
  float number;
  printf("%s", prompt);
  scanf("%f", &number);
  return number;
}

int get_operation_code() {
  int code;
  printf("1 - Sum\n");
  printf("2 - Subtract\n");
  printf("3 - Multiply\n");
  printf("4 - Divide\n");
  scanf("%d", &code);
  return code;
}

int is_valid_division(const float b, const int code) {
  if (code == 4 && b == 0) {
    printf("Cannot divide by zero!\n");
    return false;
  }

  return true;
}

float calculate(const float a, const float b, const int code) {
  switch (code) {
    case 1:
      return a + b;
    case 2:
      return a - b;
    case 3:
      return a * b;
    case 4:
      if (!is_valid_division(b, code)) {
        return 0;
      }
      return a / b;
    default:
      printf("Invalid operation code!\n");
      return 0;
  }
}

int main() {
  float a = get_number("Enter a: ");
  float b = get_number("Enter b: ");
  int code = get_operation_code();
  float result = calculate(a, b, code);
  printf("Result: %f\n", result);
  return 0;
}