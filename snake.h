#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

typedef struct Head {
    int x;
    int y;
    struct Head *next;
}Head;

typedef struct Snake {
    int length;
    Head head;
}Snake;

typedef struct Apple {
    int x;
    int y;
} Apple;

typedef struct Board {
    int width;
    int height;
    Apple apple;
}Board;

Snake initialize_snake();
Board initialize_board(Snake *snake);
Board create_board(int width, int height);

Apple eat_apple(Board* board, Snake* snake);
Apple create_apple(Board* board, Snake* snake);

void grow_snake(Snake *snake);
void update_snake(Snake *snake, Board *board);
void calculate_next_position(Snake *snake, int direction);
void calculate_next_node_position(Snake *snake, int length_index);

void print_apple(Apple apple);
void print_snake(Snake snake);
void print_board(Board board);
void print_segment(Head head, int x, int y);
int print_menu(Board* board, Snake* snake);
void print_settings(Board* board, Snake* snake);
void print_game_state(Board board, Snake snake);

int random(int max, int min);
int handle_menu(Board* board, Snake* snake);
int handle_inputs(Board* board, Snake* snake, bool* pause);
bool isSnake(Snake* snake, int x, int y);

void run_game();
void new_game();
void free_snake(Snake* snake);
void quit_game(Board* board, Snake* snake);

#endif