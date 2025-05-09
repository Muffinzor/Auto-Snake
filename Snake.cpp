#include "Snake.h"

#include <iostream>
#include "RandomGen.h"

bool Snake::is_snake_position(const int x, const int y) const {
    bool isSnake = false;
    for (const auto& pos : this->body_positions) {
        if (pos.first == x && pos.second == y) {
            isSnake = true;
            break;
        }
    }
    return isSnake;
}

bool Snake::is_snake_head(const int x, const int y) const {
    bool isHead = false;
    pair<int, int> head_pos = body_positions.front();
    if (head_pos.first == x && head_pos.second == y) {
        isHead = true;
    }
    return isHead;
}

char Snake::get_head_char() const {
    switch (direction) {
        case 0 : return '^';
        case 1 : return '>';
        case 2 : return 'v';
        case 3 : return '<';
    }
    return 'o';
}

void Snake::move() {
    if (RandomGen::randomDouble(0,1) > 1 - chance_to_turn && can_turn()) {
        chance_to_turn = 0.1;
        turn();
    } else if (collides_in_direction(direction) && can_turn()) {
        turn();
        chance_to_turn = 0.1;
    } else if (collides_in_direction(direction)) {
        body_positions.pop_back();
        length--;
        return;
    } else {
        chance_to_turn *= 1.25;
    }

    pair<int, int> head_position = body_positions.front();
    switch (direction) {
        case 0:
            head_position.second--;
            break;
        case 1:
            head_position.first++;
            break;
        case 2:
            head_position.second++;
            break;
        case 3:
            head_position.first--;
            break;
    }
    int new_head_x = head_position.first;
    int new_head_y = head_position.second;
    body_positions.insert(body_positions.begin(), {new_head_x, new_head_y});

    if (body_positions.size() > length) {
        body_positions.pop_back();
    }
    growth_counter++;
    if (growth_counter == 20) {
        length++;
        growth_counter = 0;
    }
}

bool Snake::can_turn() {
    bool can_turn = true;
    switch (direction) {
        case 0:
        case 2:
            if (collides_in_direction(1) && collides_in_direction(3)) can_turn = false;
            break;
        case 1:
        case 3:
            if (collides_in_direction(0) && collides_in_direction(2)) can_turn = false;
            break;
    }
    return can_turn;
}

void Snake::turn() {
    int head_x = body_positions.front().first;
    int head_y = body_positions.front().second;
    switch (direction) {
        case 0:
        case 2:
            if (head_x + 1 >= board_dimension - 1 || collides_in_direction(1)) {
                direction = 3;
            } else if (head_x - 1 <= 0 || collides_in_direction(3)) {
                direction = 1;
            } else {
                direction = RandomGen::randomBoolean() ? 1 : 3;
            }
            break;

        case 1:
        case 3:
            if (head_y + 1 >= board_dimension - 1 || collides_in_direction(2)) {
                direction = 0;
            } else if (head_y - 1 <= 0 || collides_in_direction(0)) {
                direction = 2;
            } else {
                direction = RandomGen::randomBoolean() ? 0 : 2;
            }
            break;
    }
}

bool Snake::collides_in_direction(int dir) const {
    int head_x = body_positions.front().first;
    int head_y = body_positions.front().second;

    switch (dir) {
        case 0: head_y -= 1; break;
        case 1: head_x += 1; break;
        case 2: head_y += 1; break;
        case 3: head_x -= 1; break;
    }

    if (head_x <= 0 || head_x >= board_dimension - 1 ||
        head_y <= 0 || head_y >= board_dimension - 1) {
        return true;
        }

    for (unsigned int i = 0; i < body_positions.size(); ++i) {
        if (body_positions[i].first == head_x && body_positions[i].second == head_y) {
            return true;
        }
    }
    return false;
}



