#include "snake.h"

void run_game() {
    Snake snake = initialize_snake();
    Board board = initialize_board(&snake);

    while (true) {
        print_game_state(board, snake);
        int direction = handle_inputs(&snake);
        if (direction != -1) {
            calculate_next_node_position(&snake, snake.length);
            calculate_next_position(&snake, direction);
            update_snake(&snake, &board);
        }
        usleep(200000); // Sleep for 200ms
    }

}

int main(void) {
    run_game();
    return EXIT_SUCCESS;
}
