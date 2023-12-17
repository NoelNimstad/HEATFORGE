#include "window.h"

Heatforge::Window::Window(int width, int height, char const * title)
{
    WIDTH = width;
    HEIGHT = height;

    // initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cout << "Failed to initialize SDL:\n" << SDL_GetError();
        exit(-1);
    }

    // initialize image loading
    if(!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "Failed to initialize SDL image:\n" << SDL_GetError() << std::endl;  
        exit(-1);
    }

    // create window
    window = SDL_CreateWindow(title, 
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED, 
                              WIDTH, 
                              HEIGHT, 
                              SDL_WINDOW_SHOWN);

    // make sure window got created correctly
    if(window == NULL) 
    {
        std::cout << "Failed to create window:\n" << SDL_GetError();
        exit(-1);
    }
}

Heatforge::Window::~Window()
{
    SDL_DestroyWindow(window);
}

Heatforge::Renderer * Heatforge::Window::CreateRenderer()
{
    // create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // mamke sure renderer got created correctly
    if(renderer == NULL)
    {
        std::cout << "Failed to create a renderer:\n" << SDL_GetError();
        exit(-1);
    }

    return new Heatforge::Renderer(renderer);
}