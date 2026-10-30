#include "snake.h"

void run_game() {
    Board board = initialize_board();
    Snake snake = initialize_snake();
    
    while (true) {
        
        print_game_state(board, snake);
        int direction = input_direction();
        if (direction == -3) grow_snake(&snake);
        if (direction != -1 && direction != -3) {
            calculate_next_node_position(&snake, snake.length);
            calculate_next_position(&snake, direction);           
            update_snake(&snake, board, direction);
        }
        usleep(200000); // Sleep for 200ms
    }

}

int main(void) {
    run_game();
    return EXIT_SUCCESS;
}
