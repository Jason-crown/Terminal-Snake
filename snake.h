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

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 5
#define BOARD_XOFFSET 12
#define BOARD_YOFFSET 6



typedef struct Head {
    int x;
    int y;
    struct Head *next;
}Head;

typedef struct Snake {
    int length;
    int health;
    Head head;
}Snake;

typedef struct Apple {
    int x;
    int y;
} Apple;

typedef struct Board {
    int width;
    int height;
    int xoffset;
    int yoffset;
    Apple apple;
}Board;



void run_game();

Board create_board(int width, int height, int xoffset, int yoffset);

Snake initialize_snake();
Board initialize_board();

void grow_snake(Snake *snake);
Apple update_snake(Snake *snake, Board board);
void calculate_next_position(Snake *snake, int direction);
void calculate_next_node_position(Snake *snake, int length_index);

int handle_inputs(Snake* snake);

void print_board(Board board);
void print_segment(Head head, int x, int y);

void print_menu();
void print_apple(Apple apple);
void print_settings();
void print_snake(Snake snake);
void print_game_state(Board board, Snake snake);

void cleanup_game(Snake* snake, Board* board);

Apple create_apple(Board* board);
Apple eat_apple(Board* board, Snake* snake);
#endif