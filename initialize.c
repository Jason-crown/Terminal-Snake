#include "snake.h"

Snake initialize_snake() {
    Snake snake;
    snake.length = 1;
    snake.health = 100;
    snake.head.x = 5;
    snake.head.y = 5;
    return snake;
}
