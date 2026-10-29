#include "snake.h"

void run_game() {
    Board board = initialize_board();
    Snake snake = initialize_snake();
    
    while (true) {
        printf("\x1b[3J\x1b[H\x1b[2J");
        print_game_state(board, snake);
        int direction = input_direction();
        if (direction == -3) grow_snake(&snake);
        if (direction != -1 && direction != -3) {
            calculate_next_position(&snake, direction);           
            update_snake(&snake, board, direction);
        }
        usleep(200000); // Sleep for 200ms
    }

}

int main(int argc, char *argv[]) {
    /*if (argc != 2) {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *map_file = argv[1];
    if (init_game(map_file) != 0) {
        fprintf(stderr, "Failed to initialize the game with map file: %s\n", map_file);
        return EXIT_FAILURE;
    }*/

    run_game();

    //cleanup_game();
    return EXIT_SUCCESS;
}
