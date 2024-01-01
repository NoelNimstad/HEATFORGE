#pragma once 

#include <SDL2/SDL.h>
#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
                    { L"w", 119 }, { L"a", 97 },
                    { L"s", 115 }, { L"d", 100 },
                    { L" ", 32 }, { L"left", 1073741904 },
                    { L"right", 1073741903 }, { L"lshift", 1073742049 },
                    { L"rshift", 1073742053 }
                };
            };
            ~Heatforge();
            
            void Start();
            void Clear();
            void Update();
            void DoVSync(bool state);
            void Hook(std::function<void()> hook);
            void ClearHooks();
            void Unhook(std::function<void()> hook);
            Spritesheet LoadSpritesheet(const char * path, int WIDTH, int HEIGHT);
            bool GetKey(const wchar_t * key);

            // variables
            bool running = true;
            int clearColor[3] = { 0, 0, 0 };
            Uint32 delta;
            std::unordered_map<int, bool> inputs;
            std::unordered_map<const wchar_t *, int> keys;
            Vector2 ZERO;
        private:
            std::vector<std::function<void()>> hooks;   
            void HandleEvent(const SDL_Event & event, std::unordered_map<int, bool> & inputs);
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