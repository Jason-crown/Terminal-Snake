#include "snake.h"

int input_direction() {
    int ch = getchar();
    switch (ch) {
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