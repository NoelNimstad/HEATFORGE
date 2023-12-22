#pragma once 

#include <SDL2/SDL.h>
#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>

#include "window.h"
#include "renderer.h"
#include "spritesheet.h"
#include "entity.h"

namespace Heatforge 
{
    class Heatforge
    {
        public:
            // functions
            Heatforge(char const * TITLE, int WIDTH, int HEIGHT, int SCALE, int ms)
                : window(WIDTH * SCALE, HEIGHT * SCALE, TITLE), renderer(window.CreateRenderer()), scale(SCALE), frameTime(ms), ZERO(0, 0) 
            {
                keys = 
                {
                    { 'w', 119 }, { 'a', 97 },
                    { 's', 115 }, { 'd', 100 }
                };
            };
            
            void HandleEvent(const SDL_Event & event, std::unordered_map<int, bool> & inputs);
            void Start();
            void End();
            void Clear();
            void Update();
            void DoVSync(bool state);
            void Hook(std::function<void()> hook);
            Spritesheet LoadSpritesheet(const char * path, int WIDTH, int HEIGHT);

            // variables
            bool running = true;
            std::vector<std::function<void()>> hooks;   
            int clearColor[3] = { 0, 0, 0 };
            Uint32 delta;
            std::unordered_map<int, bool> inputs;
            std::unordered_map<char, int> keys;
            Vector2 ZERO;
        private:
            int scale;
            std::chrono::milliseconds frameTime;
            std::unordered_map<wchar_t, int> CHAR_MAP;

            // integral parts
            Window window;
            Renderer * renderer;

            // delta time
            Uint32 NOW;
            Uint32 LAST;
    };
}