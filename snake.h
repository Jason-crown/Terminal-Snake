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
#include <pthread.h>

typedef struct Color {
    char red;
    char green;
    char blue;
} Color;

typedef struct Head {
    int x;
    int y;
    struct Head *next;
}Head;

typedef struct Snake {
    int length;
    int speed;
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

typedef struct thread_args {
    Board* board;
    Snake* snake;
    bool* pause;
} thread_args;

void run_game();
void new_game();

Snake initialize_snake();
Board initialize_board(Snake *snake);

Apple eat_apple(Board* board, Snake* snake);
Apple create_apple(Board* board, Snake* snake);

void grow_snake(Snake *snake);
int update_snake(Snake *snake, Board *board);
void calculate_next_position(Snake *snake, int direction);
void calculate_next_node_position(Snake *snake, int length_index);

Board* resize_board(Board* board, Snake* snake, int width, int height);
Snake* set_snake_speed(Snake* snake, int speed);
Snake* resize_snake(Snake* snake, int new_length);
Color* set_snake_color(Color* color);
Color* set_board_color(Color* color);

void print_apple(Apple apple);
void print_snake(Snake snake);
void print_board(Board board);

void print_segment(Head head, int x, int y);
void print_game_state(Board board, Snake snake);

int print_menu(Board* board, Snake* snake, bool* pause);
int print_settings(Board* board, Snake* snake, bool* pause);

int random(int max, int min);
bool isSnake(Snake* snake, int x, int y);

void* handle_thread(void* args);
int handle_menu(Board* board, Snake* snake, bool* pause);
int handle_inputs(Board* board, Snake* snake, bool* pause);
int handle_settings(Board* board, Snake* snake, bool* pause);


void free_snake(Snake* snake);
void quit_game(Board* board, Snake* snake);
thread_args create_thread_args(Board* board, Snake* snake, bool* pause);

#endif