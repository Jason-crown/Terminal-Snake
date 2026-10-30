#include "snake.h"

int input_direction() {
    int ch = getch();
    switch (ch) {
        case 'G':
            return -3;
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

int handle_inputs() {
    int ch = getch();
    switch (ch) {
        case 'S':
            
        case 'M':
            
        case 'N':
            
        case 'A':
            
        case 'L':
            
        default:
            return -1; // Invalid input
    }
}