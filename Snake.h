#ifndef SNAKE_H
#define SNAKE_H
#include <utility>
#include <vector>

using namespace std;

class Snake {
public:
    unsigned int length;
    bool eating_itself = false;
    vector<pair<int, int>> body_positions;

    Snake(const int length, const int board_dimension) {
        this->length = length;
        this->board_dimension = board_dimension;
        this->body_positions.emplace_back(board_dimension/2, board_dimension/2);
    }
    void move();
    bool is_snake_position(int x, int y) const;
    bool is_snake_head(int x, int y) const;
    char get_head_char() const;

private:
    int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west
    int board_dimension;
    int growth_counter = 0;
    double chance_to_turn = 0.1;

    bool can_turn();
    bool collides_in_direction(int direction) const;
    void turn();
};

#endif //SNAKE_H
