#include "snake.h"

void print_board(Board board) {
    printf("%c", 201);
    for (int i = 0; i < board.height; i++) {
        for (int j = 0; j < board.width; j++) {
            printf("%c", 186); // Left border
            printf(" "); // Empty space for the board
        }
        printf("\n");
    }
    printf("%c", 200); // Bottom left corner
    for (int j = 0; j < board.width; j++) {
        printf("%c", 205); // Bottom border
    }
    printf("%c", 188); // Bottom right corner
    printf("\n");
}

void print_segment(int x, int y) {
    // Move the cursor to the specified position
    printf("\033[%d;%dH", y + 1, x + 1); // ANSI escape code to move cursor
    printf("O"); // Print the snake segment
}

void print_snake(Snake snake) {
    Head *current = &snake.head;

    while (current != NULL) {
        print_segment(current->x, current->y);
        current = current->next;
    }
}

void print_game_state(Board board, Snake snake) {
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