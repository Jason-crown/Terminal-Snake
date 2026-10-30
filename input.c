#include "snake.h"

int handle_inputs(Snake* snake) {
    int ch = getch();
    switch (ch) {
        case 'S':
            print_settings();
            return -1;
        case 'M':
            print_menu();
            return -1;
        case 'N':
            //Reset_game();
            return -1;
        case 'G':
            grow_snake(snake);
            return -1;
        case 'w':
            return 0; // Up
        case 's':
            return 1; // Down
        case 'a':
            return 2; // Left
        case 'd':
            return 3; // Right
        default:
            return -1; // Invalid input
    }
}