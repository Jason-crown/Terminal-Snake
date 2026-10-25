#include "snake.h"

void update_snake(Snake *snake, Board board) {
    // Move the snake's head in the current direction
    // For simplicity, let's assume the snake moves right for now
    snake->head.x += 1;

    // Check for collisions with the board boundaries
    if (snake->head.x < 0 || snake->head.x >= board.width ||
        snake->head.y < 0 || snake->head.y >= board.height) {
        printf("Game Over! Snake hit the wall.\n");
        exit(EXIT_FAILURE);
    }
    // Check for collisions with itself
    // make sure not to check while the snake is still growing (i.e., when length is 1)
    if (snake->length > 1) {
        Head *current = &snake->head;
        while (current->next != NULL) {
            current = current->next;
            if (current->x == snake->head.x && current->y == snake->head.y) {
                printf("Game Over! Snake collided with itself.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    Head *current = &snake->head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Update the rest of the snake's body segments
    Head *current = &snake->head;
    while (current->next != NULL) {
        place_segment(current->x, current->y);
        current = current->next;
    }
}

void place_segment(int x, int y) {
    // This function would place a segment of the snake on the board
    // For now, we will just print the coordinates
    // In a real implementation, you would update the board's data structure to reflect the snake's position
    printf("Placing segment at (%d, %d)\n", x, y);
}

void calculate_next_position(Snake *snake, int direction) {
    // Calculate the next position of the snake's head based on the direction
    switch (direction) {
        case 0: // Up
            snake->head.y -= 1;
            break;
        case 1: // Down
            snake->head.y += 1;
            break;
        case 2: // Left
            snake->head.x -= 1;
            break;
        case 3: // Right
            snake->head.x += 1;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}
