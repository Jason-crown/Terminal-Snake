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

void change_colors(Board* board, Snake* snake, Color* color) {
    printf("What would you like to change the colors of?\n");
    printf("1. Snake\n");
    printf("2. Board\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        set_snake_color(snake, color);
    } else if (choice == 2) {
        set_board_color(board, color);
    }
}

void set_snake_color(Snake* snake, Color* color) {
    printf("what part of the snake would you like to change?\n");
    printf("1. Body\n");
    printf("2. Head\n");
    int colorChoice;
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        colorChoice = get_color_choice();
        strcpy(snake->color, color->normal[0]);
    } else if (choice == 2) {
        colorChoice = get_color_choice();
        strcpy(snake->head.color, color->bright[0]);
    }
}

void set_board_color(Board* board, Color* color) {
    printf("what part of the board would you like to change?\n");
    printf("1. Border\n");
    printf("2. Background\n");
    printf("3. Details\n");
    int colorChoice;
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        colorChoice = get_color_choice();
        strcpy(board->boarder_color, color->normal[0]);
    } else if (choice == 2) {
        colorChoice = get_color_choice();
        strcpy(board->background_color, color->background[0]);
    } else if (choice == 3) {
        colorChoice = get_color_choice();
        strcpy(board->detial_color, color->bright[0]);
    }
}

int get_color_choice() {
    printf("Choose a color:\n");
    printf("1. Red\n");
    printf("2. Yellow\n");
    printf("3. Green\n");
    printf("4. Blue\n");
    printf("5. Magenta\n");
    printf("6. Cyan\n");
    printf("7. White\n");
    int choice;
    scanf("%d", &choice);
    return choice - 1; // Return index (0-6)
}