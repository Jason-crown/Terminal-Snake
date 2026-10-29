#include "snake.h"

void print_board(Board board) {
    printf("\x1B[?25l");
    printf("\x1b[92m%c", 201);
    for (int j = 0; j < board.width; j++) {
        printf("%c", 205); // top border
    }
    printf("\x1b[92m%c\n", 187);
    for (int i = 0; i < board.height; i++){
        printf("\x1b[92m%c", 186); // Left border
        for (int j = 0; j < board.width; j++) {
            printf("\x1b[42m \x1b[0m"); // Empty space for the board
        }
        printf("\x1b[92m%c\n", 186); // right border
    }
    printf("%c", 200); // Bottom left corner
    for (int j = 0; j < board.width; j++) {
        printf("\x1b[92m%c", 205); // Bottom border
    }
    printf("\x1b[92m%c\x1b[0m", 188); // Bottom right corner
    printf("\n");
}

void print_segment(Head head, int x, int y) {
    // Move the cursor to the specified position
    printf("\033[%d;%dH", y+1, x+1); // ANSI escape code to move cursor
    if(head.x == x && head.y == y){
        printf("\x1b[91m%c\x1b[0m", 219);
    } else{
        printf("\x1b[31m%c\x1b[0m", 219);
    }
}

void print_snake(Snake snake) {
    Head *current = &snake.head;
    if (current == NULL){
        return;
    }
    
    while (current != NULL) {
        print_segment(snake.head, current->x, current->y);
        current = current->next;
    }
}

void print_game_state(Board board, Snake snake) {
    printf("\x1b[3J\x1b[H\x1b[2J");
    print_board(board);
    print_snake(snake);
}

void print_menu() {
    printf("1. Start Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
}

void print_settings() {
    printf("Settings:\n");
    printf("1. Change Board Size\n");
    printf("2. Change Snake Speed\n");
    printf("3. Back to Menu\n");
}