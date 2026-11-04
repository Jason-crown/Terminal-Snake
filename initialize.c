#include "snake.h"

thread_args create_thread_args(Board* board, Snake* snake, bool* pause) {
    thread_args args;
    args.board = board;
    args.snake = snake;
    args.pause = pause;
    return args;
}

Color*initialize_colors() {
    Color *colors = malloc(sizeof(Color));
    if (colors == NULL) exit(1);
    // List of all color inputs //q
    char* color_list[7] = {"red", "yellow", "green", "blue", "purple", "cyan", "white"};
    // List of all Normal colors //
    char* normal_colors[7] = {"\x1b[31m", "\x1b[33m", "\x1b[32m", "\x1b[34m", "\x1b[35m", "\x1b[36m", "\x1b[37m"};
    // List of all Bright colors //
    char* bright_colors[7] = {"\x1b[91m", "\x1b[93m", "\x1b[92m", "\x1b[94m", "\x1b[95m", "\x1b[96m", "\x1b[97m"};
    // List of all Background colors //
    char* background_colors[7] = {"\x1b[41m", "\x1b[43m", "\x1b[42m", "\x1b[44m", "\x1b[45m", "\x1b[46m", "\x1b[47m" };
    for (int i = 0; i < 7; i++) {
        strcpy(colors->color_list[i], color_list[i]);
        strcpy(colors->normal[i], normal_colors[i]);
        strcpy(colors->bright[i], bright_colors[i]);
        strcpy(colors->background[i], background_colors[i]);
    }
    return colors;
}

Snake initialize_snake() {
    Snake snake;
    snake.length = 1;
    snake.head.x = 0;
    snake.head.y = 0;
    snake.speed = 1; // Default speed
    snake.head.next = NULL;
    snake.character = 219;
    snake.head.character = 219;
    snake.direction = 3; // Default direction (right)
    strcpy(snake.color, "\x1b[31m"); // Initialize color to empty string
    strcpy(snake.head.color, "\x1b[91m"); // Initialize head color to empty string
    return snake;
}

Board initialize_board(Snake *snake) {
    Board board;
    board.width = 20;
    board.height = 10;
    board.apple = create_apple(&board, snake);
    board.background_character = ' ';
    strcpy(board.boarder_color, "\x1b[37m"); // Initialize color to empty string
    strcpy(board.background_color, "\x1b[40m"); // Initialize color to empty string
    strcpy(board.detial_color, "\x1b[37m"); // Initialize color to empty string
    strcpy(board.apple.color, "\x1b[91m"); // Initialize color to empty string
    return board;
}

Apple create_apple(Board* board, Snake* snake) {
    Apple apple;
    apple.x = random(board->width-1, 0);
    apple.y = random(board->height-1, 0);
    strcpy(apple.color, "\x1b[91m"); // Initialize color to empty string
    int* safe_x = malloc(sizeof(int)*board->height*board->width);
    int* safe_y = malloc(sizeof(int)*board->height*board->width);
    int n = 0;
    for (int i = 0; i < board->width; i++) {
        for (int j = 0; j < board->height; j++) {
            if(!isSnake(snake, i, j)) {
                safe_x[n] = i;
                safe_y[n] = j;
                n++;
            }
        }                
    }
    if (isSnake(snake, apple.x, apple.y)) {
        apple.x = safe_x[random(n-1,0)];
        apple.y = safe_y[random(n-1,0)];
    }
    free(safe_x);
    free(safe_y);
    return apple;
}

bool isSnake(Snake* snake, int x, int y) {
    Head* current = &snake->head;
    while (current->next != NULL) {
        if (x == current->x && y == current->y) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int random(int max, int min) {
    srand(time(NULL) ^ getpid());
    return rand() % (max-min+1)+min;
}