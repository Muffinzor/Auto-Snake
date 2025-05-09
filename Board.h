#ifndef PRINTER_H
#define PRINTER_H
#include "Snake.h"

class Board {
public:
    int dimension;
    Snake* snake;

    explicit Board(const int dimension, Snake* snake) {
        this->dimension = dimension;
        this->snake = snake;
    }

    void print_board() const;
};



#endif //PRINTER_H
