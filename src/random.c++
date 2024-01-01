#include "random.h"

void Heatforge::SeedRandom()
{
    srand((unsigned) time(0));
}

float Heatforge::Random()
{
    return (float)rand() / RAND_MAX;
}