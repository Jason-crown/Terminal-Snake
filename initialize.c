#include "snake.h"

Snake initialize_snake() {
    Snake snake;
    snake.length = 1;
    snake.health = 100;
    snake.head.x = 3;
    snake.head.y = 3;
    snake.head.next = NULL;
    return snake;
}

Board initialize_board() {
    Board board;
    board.width = BOARD_WIDTH;
    board.height = BOARD_HEIGHT;
    board.xoffset = BOARD_XOFFSET;
    board.yoffset = BOARD_YOFFSET;
    board.apple = create_apple(&board);
    return board;
}

Apple create_apple(Board* board) {
    srand(time(NULL));
    Apple apple;
    apple.x = rand() % ((board->width-1)-1)+1;
    apple.y = rand() % ((board->height-1)-1)+1;
    return apple;
}
