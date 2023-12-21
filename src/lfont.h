#pragma once 

#include <vector>
#include <iostream>
#include <unordered_map>

#include "spritesheet.h"
#include "vector.h"
#include "readfile.h"

namespace Heatforge
{
    
    class LFont
    {
        public:
            LFont(Spritesheet * spritesheet)
                : spritesheet(spritesheet) {};

            void Draw(std::vector<int> * intArray, Vector2 * position);
        private:
            Spritesheet * spritesheet;
    };
}