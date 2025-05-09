#ifndef SNAKE_H
#define SNAKE_H
#include <utility>
#include <vector>

using namespace std;

class Snake {
public:
    unsigned int length;
    int board_dimension;
    vector<pair<int, int>> body_positions;
    int direction; // 0 = north, 1 = east, 2 = south, 3 = west
    double chance_to_turn;

    explicit Snake(const int length, const int board_dimension) {
        this->length = length;
        this->growth_counter = 0;
        this->board_dimension = board_dimension;
        this->direction = 0;
        this->chance_to_turn = 0.1;
        this->body_positions.emplace_back(board_dimension/2, board_dimension/2);
    }

    void move();
    void turn();
    bool is_snake_position(int x, int y) const;
    bool is_snake_head(int x, int y) const;
    char get_head_char() const;

private:
    bool eating_itself = false;
    int growth_counter;
    bool can_turn();
    bool collides_in_direction(int direction) const;

};

#endif //SNAKE_H
