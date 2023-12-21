#include "heatforge.h"

void Heatforge::Heatforge::Start()
{
    std::cout << "Heatforge v0.4.2a\nby: Noel Nimstad" << std::endl;

    std::chrono::milliseconds last = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::chrono::milliseconds now;
        
    SDL_Event event;
    while (running) 
    {
        now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

        if (now > last + frameTime) 
        {
            auto dt = now - last;
            last = now;

            while (SDL_PollEvent(&event)) 
            {
                HandleEvent(event, inputs);
            }

            for (const auto& function : hooks) 
            {
                function();
            }

            delta = dt.count();
        } else 
        {
            SDL_Delay(1);
        }
    }
}

void Heatforge::Heatforge::HandleEvent(const SDL_Event& event, std::unordered_map<int, bool>& inputs)
{
    switch (event.type) 
    {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            inputs[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            inputs[event.key.keysym.sym] = false;
            break;
        default:
            break;
    }
}

void Heatforge::Heatforge::End()
{
    SDL_Quit();
    free(renderer);
}

void Heatforge::Heatforge::Clear()
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer -> renderer, clearColor[0], clearColor[1], clearColor[2], 255);
    SDL_RenderClear(renderer -> renderer);
}

Heatforge::Spritesheet Heatforge::Heatforge::LoadSpritesheet(char const * path, int WIDTH, int HEIGHT)
{
    SDL_Texture * texture(IMG_LoadTexture(renderer -> renderer, path));

    if(texture == NULL)
    {
        std::cout << "Failed to load spritesheet (" << path << ")\n:" << SDL_GetError();
        exit(-1);
    }

    return Spritesheet(texture, renderer -> renderer, WIDTH, HEIGHT, scale);
}

void Heatforge::Heatforge::Update()
{
    SDL_RenderPresent(renderer -> renderer);
}

void Heatforge::Heatforge::DoVSync(bool state)
{
    SDL_GL_SetSwapInterval(state);
}

std::vector<int> Heatforge::Heatforge::ConvertStringToIntArray(std::wstring string)
{
    std::vector<int> result;
    result.reserve(string.size());

    for(const wchar_t & c : string)
    {
        auto it = CHAR_MAP.find(c);
        if(it != CHAR_MAP.end())
        {
            result.push_back(it -> second);
        }
        else
        {
            std::cout << c << " is not a valid string character" << std::endl;
        }
    }

    return result;
}

void Heatforge::Heatforge::Hook(std::function<void()> hook)
{
    hooks.push_back(hook);
}