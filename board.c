#include "snake.h"

Board create_board(int width, int height, int xoffset, int yoffset) {
    Board board;
    board.width = width;
    board.height = height;
    board.xoffset = xoffset;
    board.yoffset = yoffset;
    return board;
}

void cleanup_game(Snake* snake, Board* board) {
    Head* current = &snake->head;
    Head* temp = current;
    while (current->next != NULL) {
        temp = current;
        free(current);
        current = current->next;
    }
    free(board);
}