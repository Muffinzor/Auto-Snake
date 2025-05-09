#include "Board.h"

#include <cstdio>
#include <cstdlib>

void Board::print_board() const {
    printf(" |-");
    for (int i = 1; i < dimension - 1; ++i) {
        printf("---");
    }
    printf("-| \n");

    for (int i = 1; i < dimension-1; ++i) {
        printf(" | ");
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
        printf(" |\n");
    }

    printf(" |-");
    for (int i = 1; i < dimension - 1; ++i) {
        printf("---");
    }
    printf("-| \n");
}

void Board::print_status() const {
    printf("    Snake Length : %d\n", snake->length);
    if(snake->eating_itself) {
        printf("    Status       : Eating Itself\n");
    } else {
        printf("    Status       : Moving\n");
    }
}
