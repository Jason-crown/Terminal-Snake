#include "snake.h"

void update_snake(Snake *snake, Board board, int direction) {
    // Move the snake's head in the current direction

    // Check for collisions with the board boundaries
    if (snake->head.x <= 0 || snake->head.x > board.width || snake->head.y <= 0 || snake->head.y > board.height) {
        char* condition = "non";
        if (snake->head.x <= 0) condition = "head hit left";
        if (snake->head.x > board.width) condition = "head hit right";
        if (snake->head.y <= 0) condition = "head hit top";
        if (snake->head.y > board.height) condition = "head hit bottom";
        printf("Game Over! Snake hit the wall. %s\n,", condition);
        exit(EXIT_FAILURE);
    }
    //Head *current = &snake->head;
   // while(current->next != NULL) {
    //    current = current->next;
   // }
    //current->locked = false;
    // Check for collisions with itself
    // make sure not to check while the snake is still growing (i.e., when length is 1)
    /*if (snake->length > 1) {
        Head *current = &snake->head;
        while (current->next != NULL) {
            current = current->next;
            if (current->x == snake->head.x && current->y == snake->head.y) {
                printf("Game Over! Snake collided with itself.\n");
                exit(EXIT_FAILURE);
            }
        }
    }*/
    
    // Update the rest of the snake's body segments

}

void calculate_next_position(Snake *snake, int direction) {
    // Calculate the next position of the snake's head based on the direction
    int direction_x = 0; 
    int direction_y = 0;
    switch (direction) {
        case 0: // Up
            snake->head.y -= 1;
            direction_y = -1;
            break;
        case 1: // Down
            snake->head.y += 1;
            direction_y = 1;
            break;
        case 2: // Left
            snake->head.x -= 1;
            direction_x = -1;
            break;
        case 3: // Right
            snake->head.x += 1;
            direction_x = 1;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }

}

void calculate_next_node_position(Snake *snake, Head *node) {
    // Calculate the next position of the segment of the snake based on the previous direction
    Head *current = &snake->head;
    Head *right_before = &current;
    while(current->next != NULL) {
        
        current = current->next;
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
    new_segment->locked = false;
    new_segment->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    // Find the last segment of the snake

    current->next = new_segment; // Link the new segment to the end of the snake

    snake->length += 1; // Increase the length of the snake
}

