#include "snake.h"

Board* resize_board(Board* board, Snake* snake, int width, int height) {
    board->width = width;
    board->height = height;
    board->apple = create_apple(board, snake);
    return board;
}