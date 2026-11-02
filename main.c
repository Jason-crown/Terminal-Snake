#include "snake.h"

void run_game() {
    Snake snake = initialize_snake();
    Board board = initialize_board(&snake);
    bool pause = false;
    while (true) {
        if(!pause) print_game_state(board, snake);
        int direction = handle_inputs(&board, &snake, &pause);
        if (direction >= 0) {
            calculate_next_node_position(&snake, snake.length);
            calculate_next_position(&snake, direction);
            if (update_snake(&snake, &board) == -1) {
                pause = !pause;
                printf("\033[%d;%dH\x1b[102m\x1b[94mYOU WIN\x1b[0m", 0, ((board.width-1)/2));
            }
        }
        usleep(20000); // Sleep for 200ms
    }
    
}

void quit_game(Board* board, Snake* snake) {
    free_snake(snake);
    printf("\033[%d;%dH", board->height+3, 0);
    printf("Quitting...");
    exit(1);
}

void free_snake(Snake* snake) {
    Head* current = &snake->head;
    while(current->next != NULL) {
        Head* temp = current->next;
        free(temp);
        current = current->next;
    }
}

void new_game() {
    run_game();
}

int main(void) {
    run_game();
    return EXIT_SUCCESS;
}