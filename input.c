#include "snake.h"

int handle_menu(Board* board, Snake* snake, bool* pause, Color* colors) {
    if (*pause) {
        printf("\033[%d;%dH%s%sPaused\x1b[0m", 0, ((board->width-1)/2), board->boarder_color, board->detial_color);
    }    
    int ch = getch();
    switch (ch) {
        case 'S':
            return print_settings(board, snake, pause, colors);
        case 'P':
        case 'p':
            *pause = !*pause;
            if (*pause) {
                printf("\033[%d;%dH%s%sPaused\x1b[0m", 0, ((board->width-1)/2), board->boarder_color, board->detial_color);
            }
            return -1;      
        case 'M':
            *pause = !*pause;
            return -1;
        case 'Q':
        case 'q':
            quit_game(board, snake);
            return -1;
        case 'N':
            free_snake(snake);
            new_game();
            return -1;
        default:
            printf("\033[%d;%dH", board->height+3, 0);
            printf("Invalid input. Please try again.\n");
            handle_menu(board, snake, pause, colors);
            return -1; // Invalid input
    }
}

int handle_settings(Board* board, Snake* snake, bool* pause, Color* colors) {
    int ch = getch();
    int width = 0, height = 0;
    int speed = 1;
    switch (ch) {
        case '1':
            print_game_state(*board, *snake);
            printf("\033[%d;%dH", board->height+4, 0);
            printf("Enter new width: ");
            scanf("%d", &width);
            printf("\033[%d;%dH", board->height+5, 0);
            printf("Enter new height: ");
            scanf("%d", &height);
            resize_board(board, snake, width, height);
            *pause = !*pause;
            print_game_state(*board, *snake);
            return -1;
        case '2':  
            print_game_state(*board, *snake);
            printf("\033[%d;%dH", board->height+4, 0);
            printf("Enter new snake speed: ");
            scanf("%d", &speed);
            set_snake_speed(snake, speed);
            *pause = !*pause;
            print_game_state(*board, *snake);
            return -1;
        case '3':   
            change_colors(board, snake, colors);
            *pause = !*pause;
            return -1;
        case '4':
            return print_menu(board, snake, pause, colors);
        case 'Q':
        case 'q':
            quit_game(board, snake);
            return -1;
        default:
            printf("\033[%d;%dH", board->height+3, 0);
            printf("Invalid input. Please try again.\n");
            handle_settings(board, snake, pause, colors);
            return -1; // Invalid input
    }
}

int handle_inputs(Board* board, Snake* snake, bool* pause, Color* colors) {
    int ch = getch();
    
    if (ch == 0 || ch == 224) { // Handle arrow keys
        ch = getch(); // Get the actual key code
    }
    switch (ch) {
        case 'm':
            *pause = !*pause;
            printf("\033[%d;%dH%s%sPaused\x1b[0m", 0, ((board->width-1)/2), board->boarder_color, board->detial_color);
            print_menu(board, snake, pause, colors);
            return -1;        
        case 'p':
            *pause = !*pause;
            if (*pause) {
                printf("\033[%d;%dH%s%sPaused\x1b[0m", 0, ((board->width-1)/2), board->boarder_color, board->detial_color);
            }
            return -1;
        case 'n':
            free_snake(snake);
            new_game();
            return -1;
        case 'Q':
        case 'q':
            quit_game(board, snake);
            return -1;
        case 72: // Up arrow key    
        case 'W':
            if (*pause) return -1;
            return 0; // Up
        case 80: // Down arrow key
        case 'S':
            if (*pause) return -1;
            return 1; // Down
        case 75: // Left arrow key
        case 'A':
            if (*pause) return -1;
            return 2; // Left
        case 77: // Right arrow key
        case 'D':
            if (*pause) return -1;
            return 3; // Right
        default:
            return -1; // Invalid input
    }
}