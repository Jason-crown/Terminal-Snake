#include "snake.h"

Board create_board(int width, int height) {
    Board board;
    board.width = width;
    board.height = height;
    return board;
}