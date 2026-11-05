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
    char color_list[7][9];
    char normal[7][9];
    char bright[7][9];
    char background[7][9];
    char bright_background[7][9];
} Color;

typedef struct Head {
    int x;
    int y;
    unsigned char character;
    char color[9];
    struct Head *next;
}Head;

typedef struct Snake {
    int length;
    int speed;
    Head head;
    unsigned char character;
    char color[9];
    int direction; // 0: Up, 1: Down, 2: Left, 3: Right
}Snake;

typedef struct Apple {
    int x;
    int y;
    unsigned char character;
    char color[9];
} Apple;

typedef struct Board {
    int width;
    int height;
    char boarder_color[9];
    char background_color[9];
    unsigned char background_character;
    char detial_color[9];
    Apple apple;
}Board;

typedef struct thread_args {
    Board* board;
    Snake* snake;
    bool* pause;
    Color* colors;
} thread_args;

void run_game();
void new_game();

Snake initialize_snake();
Color* initialize_colors();
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
void set_snake_color(Snake* snake, Color* color);
void set_board_color(Board* board, Color* color);
void change_colors(Board* board, Snake* snake, Color* color);
void set_apple_color(Board* board, Color* color);
int get_color_choice(void);

void set_snake_character(Snake* snake);
void set_board_character(Board* board);


void print_apple(Board board);
void print_snake(Snake snake);
void print_board(Board board);

void print_segment(Snake snake, int x, int y);
void print_game_state(Board board, Snake snake);

int print_menu(Board* board, Snake* snake, bool* pause, Color* colors);
int print_settings(Board* board, Snake* snake, bool* pause, Color* colors);

int random(int max, int min);
bool isSnake(Snake* snake, int x, int y);

void* handle_thread(void* args);
int handle_menu(Board* board, Snake* snake, bool* pause, Color* colors);
int handle_inputs(Board* board, Snake* snake, bool* pause, Color* colors);
int handle_settings(Board* board, Snake* snake, bool* pause, Color* colors);

void free_snake(Snake* snake);
void quit_game(Board* board, Snake* snake);
thread_args create_thread_args(Board* board, Snake* snake, bool* pause);

#endif