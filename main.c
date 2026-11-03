#include "snake.h"

void* handle_thread(void* args) {
    thread_args* threadArgs = (thread_args*)args;
    Board* board = threadArgs->board;
    Snake* snake = threadArgs->snake;
    bool* pause = threadArgs->pause;
    int direction = 3; // Default direction (right)
    direction = handle_inputs(board, snake, pause, threadArgs->colors);
    return (void*)(intptr_t)direction; // Return the new direction as a void pointer
}

void run_game() {
    //void* input_char;
    int direction = 3;   
    bool pause = false;
    
    //pthread_t input_thread;
    Color* colors = initialize_colors();
    Snake snake = initialize_snake();
    Board board = initialize_board(&snake);
    //thread_args args = create_thread_args(&board, &snake, &pause);
    while (true) {
        //pthread_create(&input_thread, NULL, handle_thread, &args);
        if(!pause) print_game_state(board, snake);
        direction = handle_inputs(&board, &snake, &pause, colors);
        if (direction >= 0 && direction <= 3) {
            calculate_next_node_position(&snake, snake.length);
            calculate_next_position(&snake, direction);
            if (update_snake(&snake, &board) == -1) {
                pause = !pause;
                printf("\033[%d;%dH\x1b[102m\x1b[94mYOU WIN\x1b[0m", 0, ((board.width-1)/2));
            }
        }
        /*pthread_join(input_thread, &input_char);
        if (direction != (int)(intptr_t)input_char) {
            direction = (int)(intptr_t)input_char; // Update the direction based on the input
        }*/
        usleep(20000/snake.speed); // Sleep for 20ms
    }
    
}
void quit_game(Board* board, Snake* snake) {
    free_snake(snake);
    printf("\033[%d;%dH", board->height+3, 0);
    printf("Quitting...\n");
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