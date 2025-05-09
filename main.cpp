#include <iostream>
#include <thread>
#include <chrono>
#include "Snake.h"
#include "Board.h"

void clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

int main(int argc, char* argv[]) {
    int board_size = 15;
    if (argc > 1) {
        try {
            int input_size = std::stoi(argv[1]);
            if (input_size >= 10 && input_size <= 30) {
                board_size = input_size;
            } else {
                clearScreen();
                std::cout << "Invalid board size. Using 15 as default instead.\n";
                for(unsigned int i = 3; i > 0; i--) {
                    printf("%d...\n", i);
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }
            }
        } catch (const std::exception& e) {
            clearScreen();
            std::cout << "Invalid input: must be a number. Using 15 as default instead.\n";
            for(unsigned int i = 3; i > 0; i--) {
                printf("%d...\n", i);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
    }

    int snake_size = 5;
    Snake snake(snake_size, board_size);
    Board B(board_size, &snake);
    while (true) {
        clearScreen();
        snake.move();
        B.print_board();
        B.print_status();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}