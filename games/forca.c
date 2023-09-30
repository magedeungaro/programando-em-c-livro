#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
  bool hanged;
  bool won;
  bool over;
  char* guesses;
  int guess_number;
} GameState;

typedef struct {
  int success;
  int* positions;
  int positions_qtd;
  char guess;
} GuessAnalysis;

void update_hidden_word(GuessAnalysis result, char* hidden_word) {
  for (int i = 0; i < result.positions_qtd; i++) {
    hidden_word[result.positions[i]] = result.guess;
  }
}

void print_hidden_word(char* hidden_word) {
  for (int i = 0; i < strlen(hidden_word); i++) {
    printf("%c ", hidden_word[i]);
  }

  printf("\n");
}

char* generate_word() {
  return "melancia";
}

char* hide_word(char* word) {
  char* hidden_word = malloc(sizeof(char) * strlen(word));
  for (int i = 0; i < strlen(word); i++) {
    hidden_word[i] = '_';
  }

  return hidden_word;
}

char get_letter_guess() {
  char letter_guess;
  printf("Guess a letter: ");
  scanf(" %c", &letter_guess);

  return letter_guess;
}

GuessAnalysis word_includes(char word[], char letter) {
  GuessAnalysis response = {
    success: false,
    positions: malloc(sizeof(int) * strlen(word)),
    positions_qtd: 0,
    guess: letter
  };

  int length = strlen(word);

  for (int i = 0; i < length; i++) {
    if (word[i] == letter) {
      response.success = true;
      response.positions[response.positions_qtd] = i;
      response.positions_qtd++;
    }
  }

  return response;
}

void action_strategy(GuessAnalysis result, char* hidden_word) {
  if (result.success) {
    printf("A palavra tem a letra %c \n", result.guess);
    update_hidden_word(result, hidden_word);
    // uncover the letter
  }
  else {
    printf("A palavra nao tem a letra %c \n", result.guess);
    // print part of the person
  }
}

void run_game(GameState game_state) {
  char* word = generate_word();
  char* hidden_word = hide_word(word);

  do {
    print_hidden_word(hidden_word);
    char guess = get_letter_guess();
    game_state.guesses[game_state.guess_number] = guess;
    game_state.guess_number++;

    GuessAnalysis result = word_includes(word, guess);
    action_strategy(result, hidden_word);
  } while (!game_state.over);
}

int main () {
  int max_guesses = 26;

  GameState game_state = {
    hanged: false,
    won: false,
    over: game_state.hanged || game_state.won,
    guesses: malloc(sizeof(char) * max_guesses),
    guess_number: 0
  };
  run_game(game_state);

  return 0;
}