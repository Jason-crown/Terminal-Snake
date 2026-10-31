#include "snake.h"

void update_snake(Snake *snake, Board board) {
    // Move the snake's head in the current direction

    // Check for collisions with the board boundaries
    bool wallCollisions[] = {snake->head.x <= 0, snake->head.x > board.width, snake->head.y <= 0, snake->head.y};
    char* collisionMessages[] = {"Left", "Right", "Top", "Bottom"};
    if (snake->head.x <= 0 || snake->head.x > board.width || snake->head.y <= 0 || snake->head.y > board.height) {
        for (int i = 0; i < 4; i++) {
            if (wallCollisions[i]) {
                printf("\033[%d;%dH", BOARD_HEIGHT+3, 0);
                printf("Game Over! Snake hit the wall. \n Snakes head hit the %s of the board.\n", collisionMessages[i]);
                break;
            }
        }
        exit(EXIT_FAILURE);
    }
    // Check for collisions with itself
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
    if (snake->head.x == board.apple.x && snake->head.y == board.apple.y){     
        eat_apple(&board, snake);
    }
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

void calculate_next_node_position(Snake *snake, int length_index) {
    // Calculate the next position of the segment of the snake based on the previous direction
    Head *current = &snake->head;
    Head *right_before = current;
    for (int i = 0; i < length_index; i++) {
        right_before = current;
        current = current->next;        
    }
    if (current && right_before) {
        current->x = right_before->x;
        current->y = right_before->y;
    }
    if (length_index > 0) {
        calculate_next_node_position(snake, length_index-1);
    }
}
void grow_snake(Snake *snake) {
    // Add a new segment to the snake's body
    Head *new_segment = (Head *)malloc(sizeof(Head));
    if (new_segment == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    Head *current = &snake->head;
    new_segment->x = current->x; // New segment starts at the head's position
    new_segment->y = current->y;
void grow_snake(Snake *snake) {
    // Add a new segment to the snake's body
    Head *new_segment = (Head *)malloc(sizeof(Head));
    if (new_segment == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    Head *current = &snake->head;
    new_segment->x = current->x; // New segment starts at the head's position
    new_segment->y = current->y;
    new_segment->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    // Find the last segment of the snake

    current->next = new_segment; // Link the new segment to the end of the snake

    snake->length += 1; // Increase the length of the snake
}

