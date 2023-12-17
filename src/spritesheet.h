#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Heatforge 
{
    class Spritesheet 
    {
        public:
            Spritesheet(SDL_Texture * texture, SDL_Renderer * renderer, int WIDTH, int HEIGHT, int SCALE)
                : texture(texture), renderer(renderer), width(WIDTH), height(HEIGHT), scale(SCALE) 
            {
                SDL_QueryTexture(texture, NULL, NULL, &rows, &columns);
                rows /= WIDTH;
                columns /= HEIGHT;
            };

            void SelectSprite(int index);
            void SetPosition(int x, int y);
            void Draw();
            int width;
            int height;
        private:
            SDL_Renderer * renderer;
            SDL_Texture * texture;
            SDL_Rect selection;
            SDL_Rect position;
            int rows;
            int columns;
            int scale;
    };
}