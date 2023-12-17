#pragma once 

#include <vector>
#include <iostream>
#include <unordered_map>

#include "spritesheet.h"
#include "vector.h"

namespace Heatforge
{
    
    class Font
    {
        public:
            Font(Spritesheet * spritesheet)
                : spritesheet(spritesheet) {};

            void Draw(std::vector<int> * intArray, Vector2 * position);
        private:
            Spritesheet * spritesheet;
    };
}