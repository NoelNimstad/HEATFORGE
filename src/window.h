#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "renderer.h"

namespace Heatforge
{
    class Window 
    {
        public:
            // initialize
            int WIDTH;
            int HEIGHT;
            Window(int width, int height, char const * title);
            ~Window();

            // functions
            Renderer * CreateRenderer();
            SDL_Window * window;
    };
}