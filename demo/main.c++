#include <iostream>
#include <filesystem>

#include "debug.h"
#include "physics.h"
#include "draw.h"
#include "../src/getpath.h"

int main()
{
    Heatforge::SeedRandom();

    background.SelectSprite(0);
    background.SetPosition(20, 0);

    _.Hook(&Clear);
    _.Hook(&PhysicsPass);
    _.Hook(&DrawPass);
    _.Hook(&Debug);
    _.Hook(&Update);

    _.Start();

    return 0;
}