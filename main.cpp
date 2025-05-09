#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include "Snake.h"
#include "Board.h"

void hideCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main() {
    int board_size = 15;
    int snake_size = 5;
    Snake snake(snake_size, board_size);
    Board B(board_size, &snake);
    hideCursor();
    while (true) {
        system("cls");
        snake.move();
        B.print_board();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}