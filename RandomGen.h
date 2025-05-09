#ifndef RANDOMGEN_H
#define RANDOMGEN_H

class RandomGen {
public:
    static int randomInt(int min, int max);
    static double randomDouble(double min, double max);
    static bool randomBoolean();
};

#endif //RANDOMGEN_H
