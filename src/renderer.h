#pragma once

#include <SDL2/SDL.h>

namespace Heatforge 
{
    class Renderer 
    {
        public:
            Renderer(SDL_Renderer * windowRenderer)
                : renderer(windowRenderer) {};
            ~Renderer();

            // variables
            SDL_Renderer * renderer;
    };
}