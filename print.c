#include "snake.h"

void print_board(Board board) {
    printf("\x1B[?25l");
    printf("%s%s%c", board.boarder_color, board.detial_color,201);
    for (int j = 0; j < board.width; j++) {
        printf("%c", 205); // top border
    }
    printf("%s%s%c\n\x1b[0m", board.boarder_color, board.detial_color, 187);
    for (int i = 0; i < board.height; i++){
        printf("%s%s%c",board.boarder_color, board.detial_color, 186); // Left border
        for (int j = 0; j < board.width; j++) {
            printf("%s \x1b[0m", board.background_color); // Empty space for the board
        }
        printf("%s%s%c\x1b[0m\n", board.boarder_color, board.detial_color, 186); // right border
    }
    printf("%s%s%c", board.boarder_color, board.detial_color, 200); // Bottom left corner
    for (int j = 0; j < board.width; j++) {
        printf("%c", 205); // Bottom border
    }
    printf("%s%s%c\x1b[0m", board.boarder_color, board.detial_color, 188); // Bottom right corner
    printf("\n");
}

void print_segment(Snake snake, int x, int y) {
    // Move the cursor to the specified position
    printf("\033[%d;%dH", y+2, x+2); // ANSI escape code to move cursor
    if(snake.head.x == x && snake.head.y == y){
        printf("%s%c\x1b[0m", snake.head.color, 219);
    } else{
        printf("%s%c\x1b[0m", snake.color, 219);
    }
}

void print_snake(Snake snake) {
    Head *current = &snake.head;
    if (current == NULL){
        return;
    }
    
    while (current != NULL) {
        print_segment(snake, current->x, current->y);
        current = current->next;
    }
}

void print_game_state(Board board, Snake snake) {
    printf("\x1b[3J\x1b[H\x1b[2J");
    print_board(board);
    print_apple(board);
    print_snake(snake);
    
}

void print_apple(Board board) {
    printf("\033[%d;%dH", board.apple.y+2, board.apple.x+2); // ANSI escape code to move cursor
    printf("%s%s%c\x1b[0m", board.background_color, board.apple.color, 235);
}

int print_menu(Board* board, Snake* snake, bool* pause, Color* colors) {
    printf("\033[%d;%dH", board->height+3, 0);
    printf("Menu:\n");
    printf("(P). Unpause Game\n");
    printf("(S). Game Settings\n");
    printf("(N). New Game\n");
    printf("(Q). Exit\n");
    return handle_menu(board, snake, pause, colors);
}

int print_settings(Board* board, Snake* snake, bool* pause, Color* colors) {
    printf("\033[%d;%dH", board->height+3, 0);
    printf("Settings:\n");
    printf("1. Change Board Size\n");
    printf("2. Change Snake Speed\n");
    printf("3. Change game colors\n");
    printf("4. Back to Menu\n");
    return handle_settings(board, snake, pause, colors);
}