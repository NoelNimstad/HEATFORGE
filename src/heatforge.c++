#include "heatforge.h"

void Heatforge::Heatforge::Start()
{
    std::cout << "Heatforge v0.7.0a\nby: Noel Nimstad" << std::endl;

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

Heatforge::Heatforge::~Heatforge()
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

void Heatforge::Heatforge::Hook(std::function<void()> hook)
{
    hooks.push_back(hook);
}

void Heatforge::Heatforge::Unhook(std::function<void()> hook)
{
    auto it = std::find_if(hooks.begin(), hooks.end(),
        [&hook](const std::function<void()>& storedHook) 
        {
            return storedHook.target<void()>() == hook.target<void()>();
        }
    );

    if (it != hooks.end()) 
    {
        hooks.erase(it);
        std::cout << "Hook removed successfully!" << std::endl;
    } else {
        std::cout << "Hook not found!" << std::endl;
    }
}

bool Heatforge::Heatforge::GetKey(const wchar_t * key)
{
    return inputs[keys[key]];
}

void Heatforge::Heatforge::ClearHooks()
{
    hooks.clear();
}