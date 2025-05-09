#include "Board.h"

#include <cstdio>
#include <cstdlib>

void Board::print_board() const {
    for (int i = 0; i < dimension; ++i) {
        printf(" * ");
    }
    printf("\n");

    for (int i = 1; i < dimension-1; ++i) {
        printf(" * ");
        for (int j = 1; j < dimension-1; ++j) {
            if (snake->is_snake_position(j, i)) {
                if (snake->is_snake_head(j, i)) {
                    printf(" %c ", snake->get_head_char());
                } else {
                    printf(" o ");
                }
            } else {
                printf("   ");
            }
        }
        printf(" *\n");
    }

    for (int i = 0; i < dimension; ++i) {
        printf(" * ");
    }
    printf("\n");
}
