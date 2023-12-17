#include <iostream>
#include <vector>
#include <sstream>

#include "../src/heatforge.h"
#include "../src/spritesheet.h"
#include "../src/font.h"
#include "../src/vector.h"
#include "../src/collider.h"
#include "../src/text.h"

Heatforge::Heatforge engine(320, 240, "Demo", 3, 16);

Heatforge::Spritesheet MiniStadAtlas = engine.LoadSpritesheet("../Resources/MiniStadAtlas.png", 3, 5);
Heatforge::Font MiniStad(&MiniStadAtlas);
Heatforge::Text version("V0.4.2A", &engine, &MiniStad, 289, 231);
Heatforge::Text FPS("ERROR", &engine, &MiniStad, 289, 224);

Heatforge::Vector2 velocity(0, 0);
Heatforge::Spritesheet playerSprite = engine.LoadSpritesheet("../Resources/player.png", 9, 12);
Heatforge::Vector2 position(156, 114);
Heatforge::Entity player(&playerSprite, &position);

Heatforge::Spritesheet wallSprite = engine.LoadSpritesheet("../Resources/wall.png", 12, 40);
Heatforge::Vector2 wallPosition(200, 100);
Heatforge::Entity wall(&wallSprite, &wallPosition);

const int SPEED = 10;
std::vector<Heatforge::Collider*> colliders;

void ClearScreen()
{
    engine.Clear();
}

void DebugInformation()
{   
    FPS.ChangeText("FPS: " + std::to_string(1000 / engine.delta));
    FPS.Draw();
    version.Draw();
}

void PhysicsPass()
{
    velocity.x = engine.inputs[engine.keys['d']] - engine.inputs[engine.keys['a']];
    velocity.y = engine.inputs[engine.keys['s']] - engine.inputs[engine.keys['w']];
    position += velocity * (engine.delta / SPEED);

    if(player.collider.CalculateCollisions(&colliders))
    {
        position += !velocity;
    }
}

void DrawPass()
{
    player.Draw();
    wall.Draw();
}

void UpdateScreen()
{
    engine.Update();
}

int main()
{
    colliders.push_back(&wall.collider);

    engine.hooks.push_back(&ClearScreen);
    engine.hooks.push_back(&DebugInformation);
    engine.hooks.push_back(&PhysicsPass);
    engine.hooks.push_back(&DrawPass);
    engine.hooks.push_back(&UpdateScreen);

    engine.Start();
    engine.End();

    return 0;
}