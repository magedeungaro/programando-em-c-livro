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

typedef struct {
  int tries;
  int secret_number;
  int min_guess;
  int max_guess;
} GameParams;

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
  printf("  ____  \n");
  printf(" /    \\ \n");
  printf("|  ▓▓▓▓\\ \n");
  printf(" \\▓▓| ▓▓ \n");
  printf("   /  ▓▓ \n");
  printf("  |  ▓▓  \n");
  printf("   \\▓▓   \n");
  printf("  |  \\   \n");
  printf("   \\▓▓  \n\n");
  printf("* Bem-vindo ao Jogo de Adivinhação *\n\n");
  printf("************************************\n");
}

void seed_random() {
  int seconds = time(NULL);
  srand(seconds);
}

int generate_secret_number(const int min, const int max) {
  seed_random();
  return rand() % (max - min + 1) + min;
}

int* get_guess_range() {
  printf("Deseja configurar o intervalo de números? (y/n): ");
  char answer;
  int min = 0;
  int max = 100;
  scanf(" %c", &answer);

  if (answer == 'y') {
    printf("Min: ");
    scanf("%d", &min);
    printf("Max: ");
    scanf("%d", &max);
  }

  static int range[2];
  range[0] = min;
  range[1] = max;

  return range;
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

int get_tries(const int difficulty) {
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

int get_guess(GameParams game_params) {
  int guess;
  int min = game_params.min_guess;
  int max = game_params.max_guess;
  int unacceptable_guess = true;

  do {
    printf("Qual é o seu chute? ");
    scanf("%d", &guess);
    unacceptable_guess = guess < min || guess > max;

    if (unacceptable_guess) {
      printf("Chute inválido. Apenas valores entre %d e %d.\n\n", min, max);
    }
  } while (unacceptable_guess);

  return guess;
}

int analyze_result(const int guess, const int secret_number) {
  if(guess == secret_number) {
    printf("Parabéns! Você acertou!\n\n");
    return true;
  }
  else if (guess > secret_number) {
    printf("Seu chute foi maior do que o número secreto!\n\n");
  }
  else {
    printf("Seu chute foi menor do que o número secreto!\n\n");
  }

  return false;
}

void run_game(const GameParams game_params) {
  int guessed_right = false;
  int current_try;
  int guess;

  for (int i = 0; !guessed_right && i < game_params.tries; i++) {
    current_try = i + 1;
    int has_tries = current_try < game_params.tries;

    printf("----------------------------------------\n");
    printf("Tentativa %d de %d\n", current_try, game_params.tries);
    guess = get_guess(game_params);
    guessed_right = analyze_result(guess, game_params.secret_number);
  }
  
  ScoreParams score_params = {game_params.tries, game_params.secret_number, guess, current_try};
  int score = calculate_score(score_params);

  if (!guessed_right) {
    printf("Você perdeu! Tente novamente ~ \n");
  }
  printf("O número secreto era %d\n", game_params.secret_number);
  printf("Seu score foi de %d\n", score);
}

int main() {
  print_welcome();
  int difficulty = get_dificulty();
  int* range = get_guess_range();
  int secret_number = generate_secret_number(range[0], range[1]);
  printf("DEBUG - Número secreto: %d\n", secret_number);
  int tries = get_tries(difficulty);
  GameParams game_params = {tries, secret_number, range[0], range[1]};
  run_game(game_params);
  printf("Obrigada por jogar!\n\n");

  return 0;
}