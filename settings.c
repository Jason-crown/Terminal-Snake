#include "snake.h"

Board* resize_board(Board* board, Snake* snake, int width, int height) {
    board->width = width;
    board->height = height;
    board->apple = create_apple(board, snake);
    return board;
}
Snake* set_snake_speed(Snake* snake, int speed) {
    if (speed < 1) {
        printf("Snake speed must be at least 1.\n");
        return snake;
    }
    snake->speed = speed;
    return snake;
}

Snake* resize_snake(Snake* snake, int new_length) {
    if (new_length < 1) {
        printf("Snake length must be at least 1.\n");
        return snake;
    }

    // If the new length is less than the current length, truncate the snake
    if (new_length < snake->length) {
        Head* current = &snake->head;
        for (int i = 1; i < new_length; i++) {
            current = current->next;
        }
        // Free the remaining segments
        Head* temp = current->next;
        current->next = NULL;
        while (temp != NULL) {
            Head* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    // If the new length is greater than the current length, grow the snake
    else if (new_length > snake->length) {
        for (int i = snake->length; i < new_length; i++) {
            grow_snake(snake);
        }
    }

    snake->length = new_length;
    return snake;
}

Color* set_snake_color(Color* color) {
    return color;
}

Color* set_board_color(Color* color) {
    return color;
}