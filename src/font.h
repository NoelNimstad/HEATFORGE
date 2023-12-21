#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>

#include "spritesheet.h"
#include "vector.h"
#include "readfile.h"

namespace Heatforge
{
    class Font
    {
        public:
            Font(const char * path);

            void Draw(std::vector<int> * intArray, Vector2 * position);
        private:
            Spritesheet spritesheet;
    };
}