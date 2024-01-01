#include <iostream>
#include <filesystem>

#include "debug.h"
#include "screen.h"

int main()
{
    _.Hook(&Clear);
    _.Hook(&Debug);
    _.Hook(&Update);

    _.Start();

    return 0;
}