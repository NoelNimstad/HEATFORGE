#include "renderer.h"

Heatforge::Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
}