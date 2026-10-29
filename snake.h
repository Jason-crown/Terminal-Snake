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

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 25
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

typedef struct Board {
    int width;
    int height;
    int xoffset;
    int yoffset;
}Board;

void run_game();
Board create_board(int width, int height, int xoffset, int yoffset);
Snake initialize_snake();
Board initialize_board();
void update_snake(Snake *snake, Board board, int direction);
void calculate_next_position(Snake *snake, int direction);
void calculate_next_node_position(Snake *snake, int length_index);
void grow_snake(Snake *snake);
int input_direction();
void print_board(Board board);
void print_segment(Head head, int x, int y);
void print_snake(Snake snake);
void print_game_state(Board board, Snake snake);
void print_menu();
void print_settings();
void place_segment(int* prv_x, int* prv_y, int* cur_x, int* cur_y);

#endif