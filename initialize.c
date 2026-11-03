#include "snake.h"

thread_args create_thread_args(Board* board, Snake* snake, bool* pause) {
    thread_args args;
    args.board = board;
    args.snake = snake;
    args.pause = pause;
    return args;
}

Snake initialize_snake() {
    Snake snake;
    snake.length = 1;
    snake.head.x = 0;
    snake.head.y = 0;
    snake.head.next = NULL;
    return snake;
}

Board initialize_board(Snake *snake) {
    Board board;
    board.width = 20;
    board.height = 10;
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
    free(safe_x);
    free(safe_y);
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