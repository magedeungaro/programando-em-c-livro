#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
  int hanged;
  int won;
  int over;
} GameState;

  typedef struct {
    int success;
    int position;
    char guess;
  } GuessAnalysis;

int randomize_position(int max) {
  srand(time(NULL));

  return rand() % max;
}

char* generate_word() {
  return "melancia";
}

char get_letter_guess() {
  char letter_guess;
  printf("Guess a letter: ");
  scanf(" %c", &letter_guess);

  return letter_guess;
}

GuessAnalysis word_includes(char word[], char letter) {
  GuessAnalysis response = { success: false, position: -1, guess: letter };

  int length = strlen(word);

  for (int i = 0; i < length; i++) {
    if (word[i] == letter) {
      response.success = true;
      response.position = i;
    }
  }

  return response;
}

void action_strategy(GuessAnalysis result) {
  if (result.success) {
    printf("A palavra tem a letra %c na posicao %d \n", result.guess, result.position);
    // uncover the letter
  }
  else {
    printf("A palavra nao tem a letra %c \n", result.guess);
    // print part of the person
  }
}

void run_game() {
  char* word = generate_word();
  GameState game_state = {
    hanged: false,
    won: false,
    over: game_state.hanged || game_state.won
  };

  do {
    char guess = get_letter_guess();
    GuessAnalysis result = word_includes(word, guess);
    action_strategy(result);
  } while (!game_state.over);
}

int main () {
  run_game();

  return 0;
}