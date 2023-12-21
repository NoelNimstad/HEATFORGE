#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "readfile.h"
#include "tile.h"
#include "spritesheet.h"

namespace Heatforge 
{
    class Tilemap 
    {
        public:
            Tilemap(Spritesheet * spritesheet, std::wstring path);
            std::vector<Tile> tiles;
            void Draw();
        private:
            Spritesheet * spritesheet;
    };
}