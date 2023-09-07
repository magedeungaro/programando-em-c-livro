#include <stdio.h>

void print_welcome() {
  printf("\n");
  printf("************************************\n");
  printf("* Bem-vindo ao Jogo de Adivinhação *\n");
  printf("************************************\n");
}

int generate_secret_number() {
  return 42;
}

int get_guess() {
  int guess;
  printf("Qual é o seu chute? ");
  scanf("%d", &guess);

  return guess;
}

void print_result(const int guess, const int secret_number) {
  if(guess == secret_number) {
    printf("Parabéns! Você acertou!\n");
  }
  else if (guess > secret_number) {
    printf("Seu chute foi maior do que o número secreto!\n");
  }
  else {
    printf("Seu chute foi menor do que o número secreto!\n");
  }
}

int main() {
  print_welcome();
  int secret_number = generate_secret_number();
  int guess = get_guess();
  print_result(guess, secret_number);

  return 0;
}