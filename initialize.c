#include "snake.h"

Snake initialize_snake() {
    Snake snake;
    snake.length = 1;
    snake.head.x = 1;
    snake.head.y = 1;
    snake.head.next = NULL;
    return snake;
}

Board initialize_board(Snake *snake) {
    Board board;
    board.width = BOARD_WIDTH;
    board.height = BOARD_HEIGHT;
    board.apple = create_apple(&board, snake);
    return board;
}

Apple create_apple(Board* board, Snake* snake) {
    Apple apple;
    apple.x = random(board->width-1, 0);
    apple.y = random(board->height-1, 0);
    int* safe_x = malloc(sizeof(int)*board->height*board->width);
    int* safe_y = malloc(sizeof(int)*board->height*board->width);
    int n = 0;
    Head* current = &snake->head;
    for (int i = 0; i < board->width; i++) {
        for (int j = 0; j < board->height; j++) {
            if(!isSnake(snake, i, j)) {
                safe_x[n] = i;
                safe_y[n] = j;
                n++;
            }
        }                
    }
    if (isSnake(snake, apple.x, apple.y)) {
        apple.x = safe_x[random(n-1,0)];
        apple.y = safe_y[random(n-1,0)];
    }
    return apple;
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