#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int tries;
  int secret_number;
  int guess;
  int current_try;
} ScoreParams;

int array_includes(const int array[], int element) {
  int length = *(&array + 1) - array;

  for (int i = 0; i < length; i++) {
    if (array[i] == element) {
        return true;
    }
  }

  return false;
}

void print_welcome() {
  printf("\n");
  printf("************************************\n");
  printf("* Bem-vindo ao Jogo de Adivinhação *\n");
  printf("************************************\n");
}

void seed_random() {
  int seconds = time(NULL);
  srand(seconds);
}

int generate_secret_number() {
  seed_random();
  return rand() % 100 + 1;
}

int get_dificulty() {
  int difficulty;
  int valid_choice = false;
  int choices[] = {1, 2, 3, 12};

  do {
    printf("Qual a dificuldade? \n");
    printf("1 - Fácil \n");
    printf("2 - Médio \n");
    printf("3 - Difícil \n");
    printf("12 - Impossível \n");
    scanf("%d", &difficulty);

    valid_choice = array_includes(choices, difficulty);
  } while (!valid_choice);

  printf("A dificuldade escolhida foi %d\n", difficulty);
  return difficulty;
}

int set_tries(const int difficulty) {
  const int max_tries = 24;

  return max_tries / difficulty;
}

int calculate_score(const ScoreParams score_params) {
  const int initial_score = 10000;
  const int try_modifier = ((int)pow(score_params.current_try, 2) * 3);
  const int number_delta = abs(score_params.secret_number - score_params.guess);
  int score = initial_score - try_modifier - number_delta - score_params.tries;
  
  return score;
}

int get_guess() {
  int guess;
  int unacceptable_guess = true;

  do {
    printf("Qual é o seu chute? ");
    scanf("%d", &guess);
    unacceptable_guess = guess < 0 || guess > 100;

    if (unacceptable_guess) {
      printf("Chute inválido. Apenas valores entre 0 e 100.\n");
    }
  } while (unacceptable_guess);

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
  int guess;

  for (int i = 0; !guessed_right && i < tries; i++) {
    current_try = i + 1;
    int has_tries = current_try < tries;

    printf("----------------------------------------\n");
    printf("Tentativa %d de %d\n", current_try, tries);
    guess = get_guess();
    guessed_right = analyze_result(guess, secret_number);
  }
  
  ScoreParams score_params = {tries, secret_number, guess, current_try};
  int score = calculate_score(score_params);

  if (!guessed_right) {
    printf("Você perdeu! Tente novamente ~ \n");
  }
  printf("O número secreto era %d\n", secret_number);
  printf("Seu score foi de %d\n", score);
}

int main() {
  print_welcome();
  int secret_number = generate_secret_number();
  printf("Número secreto: %d\n", secret_number);
  int difficulty = get_dificulty();
  int tries = set_tries(difficulty);
  run_game(tries, secret_number);
  printf("Obrigada por jogar!\n");

  return 0;
}