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

Board initialize_board(Snake *snake) {
    Board board;
    board.width = BOARD_WIDTH;
    board.height = BOARD_HEIGHT;
    board.xoffset = BOARD_XOFFSET;
    board.yoffset = BOARD_YOFFSET;
    board.apple = create_apple(&board, snake, 1);
    return board;
}

Apple create_apple(Board* board, Snake* snake, int seedCounter) {
    
    srand((time(NULL)+1)*seedCounter);
    Apple apple;
    apple.x = rand() % ((board->width-1)-1)+1;
    apple.y = rand() % ((board->height-1)-1)+1;
    Coordinates* lists = emty_spaces(board, snake, snake_coords(snake));
    for (int i = 0; i < board->height * board->width-snake->length; i++) {
        //printf(" %d - (%d, %d)\n ", i, lists[i].x, lists[i].y);
    }
    Head *current = &snake->head;
    while(current->next != NULL) {
        if (current->x == apple.x && current->y == apple.y) {
            int setRand = rand() % ((((board->height * board->width) - snake->length)-1)+1);
            //printf("%d, %d, %d", temp2[0].x, temp2[1].x, temp2[2].x);
            //apple.x = temp2[setRand].x;
            //apple.y = temp2[setRand].y;
        }
        current = current->next;
    }
    return apple;
}
