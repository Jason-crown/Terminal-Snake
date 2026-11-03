#include "snake.h"

int handle_menu(Board* board, Snake* snake, bool* pause) {
        if (*pause) {
            printf("\033[%d;%dH\x1b[102m\x1b[94mPaused\x1b[0m", 0, ((board->width-1)/2));
        }    
    int ch = getch();
    switch (ch) {
        case 'S':
            return print_settings(board, snake, pause);
        case 'P':
        case 'p':
            *pause = !*pause;
            if (*pause) {
                printf("\033[%d;%dH\x1b[102m\x1b[94mPaused\x1b[0m", 0, ((board->width-1)/2));
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
            return -1; // Invalid input
    }
}

int handle_settings(Board* board, Snake* snake, bool* pause) {
    int ch = getch();
    int width = 0, height = 0;
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
            //change_Snake_speed();
            return -1;
        case '3':   
            //change_color();
            return -1;
        case '4':
            return print_menu(board, snake, pause);
        case 'Q':
        case 'q':
            quit_game(board, snake);
            return -1;
        default:
            printf("\033[%d;%dH", board->height+3, 0);
            printf("Invalid input. Please try again.\n");
            handle_settings(board, snake, pause);
            return -1; // Invalid input
    }
}

int handle_inputs(Board* board, Snake* snake, bool* pause) {
    int ch = getch();
    switch (ch) {
        case 'M':
            *pause = !*pause;
            printf("\033[%d;%dH\x1b[102m\x1b[94mPaused\x1b[0m", 0, ((board->width-1)/2));
            print_menu(board, snake, pause);
            return -1;        
        case 'P':
        case 'p':
            *pause = !*pause;
            if (*pause) {
                printf("\033[%d;%dH\x1b[102m\x1b[94mPaused\x1b[0m", 0, ((board->width-1)/2));
            }
            return -1;
        case 'N':
            free_snake(snake);
            new_game();
            return -1;
        case 'Q':
        case 'q':
            quit_game(board, snake);
            return -1;
        case 'W':        
        case 'w':
            if (*pause) return -1;
            return 0; // Up
        case 'S':
        case 's':
            if (*pause) return -1;
            return 1; // Down
        case 'A':
        case 'a':
            if (*pause) return -1;
            return 2; // Left
        case 'D':
        case 'd':
            if (*pause) return -1;
            return 3; // Right
        default:
            return -1; // Invalid input
    }
}