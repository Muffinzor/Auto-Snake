#include <iostream>
#include <thread>
#include <chrono>
//#include <windows.h>
#include "Snake.h"
#include "Board.h"

void clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

int main() {
    int board_size = 15;
    int snake_size = 5;
    Snake snake(snake_size, board_size);
    Board B(board_size, &snake);
    while (true) {
        clearScreen();
        snake.move();
        B.print_board();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}