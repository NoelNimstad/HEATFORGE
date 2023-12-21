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
                CHAR_MAP = 
                {
                    { 'A', 0 }, { 'B', 1 },
                    { 'C', 2 }, { 'D', 3 },
                    { 'E', 4 }, { 'F', 5 },
                    { 'G', 6 }, { 'H', 7 },
                    { 'I', 8 }, { 'J', 9 },
                    { 'K', 10 }, { 'L', 11 },
                    { 'M', 12 }, { 'N', 13 },
                    { 'O', 14 }, { 'P', 15 },
                    { 'Q', 16 }, { 'R', 17 },
                    { 'S', 18 }, { 'T', 19 },
                    { 'U', 20 }, { 'V', 21 },
                    { 'W', 22 }, { 'X', 23 },
                    { 'Y', 24 }, { 'Z', 25 },
                    { '1', 26 }, { '2', 27 },
                    { '3', 28 }, { '4', 29 },
                    { '5', 30 }, { '6', 31 },
                    { '7', 32 }, { '8', 33 },
                    { '9', 34 }, { ':', 35 },
                    { '-', 36 }, { '+', 37 },
                    { ' ', 39 }, { '0', 14 },
                    { '.', 38 }
                }; 

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
            std::vector<int> ConvertStringToIntArray(std::wstring string);

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