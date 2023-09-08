#include <stdio.h>
#include <stdbool.h>
#include <math.h>


void print_welcome() {
  printf("\n");
  printf("************************************\n");
  printf("* Bem-vindo ao Jogo de Adivinhação *\n");
  printf("************************************\n");
}

int generate_secret_number() {
  return 42;
}

int set_tries() {
  return 3;
}

int calculate_score(const int current_try) {
  const int initial_score = 1000;
  int score = initial_score - ((int)pow(current_try, 3) * 15);
  
  return score;
}

int get_guess() {
  int guess;
  printf("Qual é o seu chute? ");
  scanf("%d", &guess);
  int unacceptable_guess = guess < 0 || guess > 100;

  while (unacceptable_guess) {
    printf("Chute inválido. Apenas valores entre 0 e 100.\n");
    scanf("%d", &guess);
  }
  return guess;
}

int analyze_result(const int guess, const int secret_number) {
  if(guess == secret_number) {
    printf("Parabéns! Você acertou!\n");
    return true;
  }
  else if (guess > secret_number) {
    printf("Seu chute foi maior do que o número secreto!\n");
  }
  else {
    printf("Seu chute foi menor do que o número secreto!\n");
  }

  return false;
}

void run_game(int tries, const int secret_number) {
  int guessed_right = false;
  int current_try;

  for (int i = 0; !guessed_right && i < tries; i++) {
    current_try = i + 1;
    int has_tries = current_try < tries;
    int guess = get_guess();
    printf("Tentativa %d de %d\n", current_try, tries);
    guessed_right = analyze_result(guess, secret_number);
  }

  if(guessed_right) {
    int score = calculate_score(current_try);
    printf("Seu score foi de %d\n", score);
  }
}

int main() {
  print_welcome();
  int secret_number = generate_secret_number();
  int tries = set_tries();
  run_game(tries, secret_number);
  printf("Obrigada por jogar!\n");

  return 0;
}