#include "snake.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *map_file = argv[1];
    if (init_game(map_file) != 0) {
        fprintf(stderr, "Failed to initialize the game with map file: %s\n", map_file);
        return EXIT_FAILURE;
    }

    run_game();

    cleanup_game();
    return EXIT_SUCCESS;
}
