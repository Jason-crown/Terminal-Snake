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

    // Update the rest of the snake's body segments
    Head *current = &snake->head;
    while (current->next != NULL) {
        current = current->next;
    }
}