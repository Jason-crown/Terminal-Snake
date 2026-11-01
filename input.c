#include "snake.h"

int handle_menu(Board* board, Snake* snake) {
    int ch = getch();
    switch (ch) {
        case 'S':
            print_settings(board, snake);
        case 'P':      
        case 'M':   
            return -2;
        case 'Q':
        case 'q':
            quit_game(board, snake);
            return -1;
        case 'N':
            return -3;
        default:
            return -1; // Invalid input
    }
}

int handle_inputs(Board* board, Snake* snake, bool* pause) {
    int ch = getch();
    switch (ch) {
        case 'P':
            return -2;
        case 'M':
            return print_menu(board, snake);
        case 'N':
            return -3;
        case 'Q':
        case 'q':
            quit_game(board, snake);
            return -1;
        case 'W':        
        case 'w':
            if (*pause) return -1;
            return 0; // Up
        case 'S':
        case 's':
            if (*pause) return -1;
            return 1; // Down
        case 'A':
        case 'a':
            if (*pause) return -1;
            return 2; // Left
        case 'D':
        case 'd':
            if (*pause) return -1;
            return 3; // Right
        default:
            return -1; // Invalid input
    }
}