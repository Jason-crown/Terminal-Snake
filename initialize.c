#include "snake.h"

Snake initialize_snake() {
    Snake snake;
    snake.length = 1;
    snake.health = 100;
    snake.head.x = 2;
    snake.head.y = 2;
    snake.head.next = NULL;
    return snake;
}

Board initialize_board(Snake *snake) {
    Board board;
    board.width = BOARD_WIDTH;
    board.height = BOARD_HEIGHT;
    board.xoffset = BOARD_XOFFSET;
    board.yoffset = BOARD_YOFFSET;
    board.apple = create_apple(&board, snake);
    return board;
}

Apple create_apple(Board* board, Snake* snake) {
    Apple apple;
    return rec_apple(board, snake, &apple);
}

Apple rec_apple(Board* board, Snake* snake, Apple* apple) {
    apple->x = random(board->width-1, 0);
    apple->y = random(board->height-1, 0);
    Head* current = &snake->head;
    while (current->next != NULL) {
        if (apple->x == current->x && apple->y == current->y) {
            usleep(10000);
            rec_apple(board, snake, apple);                

        }
        current = current->next;
    }
    return *apple;
}

bool isSnake(Snake* snake, int x, int y) {
    Head* current = &snake->head;
    while (current->next != NULL) {
        if (x == current->x && y == current->y) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int random(int max, int min) {
    srand(time(NULL) ^ getpid());
    return rand() % (max-min+1)+min;
}