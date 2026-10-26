#include "snake.h"

Board create_board(int width, int height, int xoffset, int yoffset) {
    Board board;
    board.width = width;
    board.height = height;
    board.xoffset = xoffset;
    board.yoffset = yoffset;
    return board;
}
