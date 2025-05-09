#include "RandomGen.h"
#include <random>

double RandomGen::randomDouble(const double min, const double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
}
bool RandomGen::randomBoolean() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);
    return dist(gen) == 1;
}