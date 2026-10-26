#include "snake.h"

void run_game() {
    Board board = initialize_board();
    Snake snake = initialize_snake();

    while (true) {
        printf("\x1b[3J\x1b[H\x1b[2J");
        print_game_state(board, snake);
        int ch = getch();
        int direction;
        switch (ch) {
            case 'w':
                direction = 0; // Up
                break;
            case 's':
                direction = 1; // Down
                break;
            case 'a':
                direction = 2; // Left
                break;
            case 'd':
                direction = 3; // Right
                break;
            default:
                direction = -1; // Invalid input
                break;
        }
        if (direction != -1) {
            calculate_next_position(&snake, direction);
            update_snake(&snake, board);
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
