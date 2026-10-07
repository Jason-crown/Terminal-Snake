#ifndef SNAKE.H
#define SNAKE.H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6
#define BOARD_XOFFSET 12
#define BOARD_YOFFSET 6

typedef struct Snake {
    int length;
    int health;
    Head head;
}Snake;

typedef struct Head {
    Head *next;
}Head;

typedef struct Board {
    int width;
    int height;
}Board;

#endif