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
    printf("2. Board\ninput: ");
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline character left in the input buffer
    if (choice == 1) {
        set_snake_color(snake, color);
    } else if (choice == 2) {
        set_board_color(board, color);
    } else {
        printf("Invalid choice. Please try again.\n");
        change_colors(board, snake, color);
    }
}

void set_snake_color(Snake* snake, Color* color) {
    printf("what part of the snake would you like to change?\n");
    printf("1. Body\n");
    printf("2. Head\ninput: ");
    int colorChoice;
    int choice;
    scanf("%d[1-2]", &choice);
    getchar(); // Consume the newline character left in the input buffer
    if (choice == 1) {
        colorChoice = get_color_choice();
        strcpy(snake->color, color->normal[colorChoice]);
    } else if (choice == 2) {
        colorChoice = get_color_choice();
        strcpy(snake->head.color, color->bright[colorChoice]);
    } else {
        printf("Invalid choice. Please try again.\n");
        set_snake_color(snake, color);
    }
}

void set_board_color(Board* board, Color* color) {
    printf("what part of the board would you like to change?\n");
    printf("1. Border\n");
    printf("2. Background\n");
    printf("3. Details\ninput: ");
    int colorChoice;
    int choice;
    scanf("%d[1-3]", &choice);
    getchar(); // Consume the newline character left in the input buffer
    if (choice == 1) {
        colorChoice = get_color_choice();
        strcpy(board->boarder_color, color->normal[colorChoice]);
    } else if (choice == 2) {
        colorChoice = get_color_choice();
        strcpy(board->background_color, color->background[colorChoice]);
    } else if (choice == 3) {
        colorChoice = get_color_choice();
        strcpy(board->detial_color, color->bright[colorChoice]);
    }else {
        printf("Invalid choice. Please try again.\n");
        set_board_color(board, color);
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
    printf("input: ");
    int choice;
    scanf("%d[1-7]", &choice);
    getchar(); // Consume the newline character left in the input buffer
    if (choice < 1 || choice > 7) {
        printf("Invalid choice. Please try again.\n");
        return get_color_choice();
    }
    printf("You chose color %d\n", choice);
    return choice - 1; // Return index (0-6)
}

void set_snake_character(Snake* snake) {
    printf("what part of the snake would you like to change?\n");
    printf("1. Body\n");
    printf("2. Head\ninput: ");
    char invalidInputs[] = {'\b', '\t', '\0', '\r', '\n'};
    int choice;
    int input;
    scanf("%d[1-2]", &choice);
    getchar(); // Consume the newline character left in the input buffer
    printf("\ninput the new character: ");
    scanf("%d", &input);
    getchar();
    if (choice == 1) snake->character = input;
    else if (choice == 2) snake->head.character = input;
    for(int i = 0; i < 5; i++) {
        if(input == invalidInputs[i]) {
            set_snake_character(snake);
        }
    }
    
}

void set_board_character(Board* board) {
    char invalidInputs[] = {'\b', '\t', '\0', '\r', '\n'};
    int input;
    printf("Chnage the character of the board background? (1 for yes, 0 for no): ");
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline character left in the input buffer
    printf("\ninput the new character: ");
    scanf("%d", &input);
    getchar();
    if (choice == 1) board->background_character = input;
    for(int i = 0; i < 5; i++) {
        if(input == invalidInputs[i]) {
            set_board_character(board);
        }
    }
    
}

void set_apple_color(Board* board, Color* color) {
    int colorChoice = get_color_choice();
    strcpy(board->apple.color, color->bright[colorChoice]);
}

void set_apple_character(Board* board) {
    char invalidInputs[] = {'\b', '\t', '\0', '\r', '\n'};
    int input;
    char inputC;
    printf("Chnage the character of the apple? (1 for yes, 0 for no): ");
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline character left in the input buffer    
    printf("How would you like to input it?\n");
    printf("(1) Ascii\n");
    printf("(2) Character\n");
    printf("Type: ");
    int typeChoice;
    scanf("%d[1-2]", &typeChoice);    
    getchar();
    printf("\ninput the new character: ");
    if (typeChoice == 1) scanf("%d", &input);
    else scanf("%c", &inputC);
    getchar();
    if (choice == 1) board->apple.character = ((typeChoice == 1)? input:inputC);
    for(int i = 0; i < 5; i++) {
        if(input == invalidInputs[i]) {
            set_apple_character(board);
        }
    }
    
}