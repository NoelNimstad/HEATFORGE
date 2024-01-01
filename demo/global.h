#pragma once
#include <iostream>
#include <vector>

#include "../src/entity.h"
#include "../src/collider.h"
#include "../src/heatforge.h"
#include "../src/font.h"
#include "../src/text.h"
#include "../src/random.h"
#include "../src/getpath.h"

// global variables
extern float g;
float g = 0.001;
extern int score;
int score = 0;
extern Heatforge::Vector2 scorePosition;
Heatforge::Vector2 scorePosition(23, 3);
extern std::string path;
std::string path(Heatforge::GetPath().string() + "/");

extern Heatforge::Heatforge _;
Heatforge::Heatforge _("火男", 320, 240, 3, 2);
extern Heatforge::Font MiniStad;
Heatforge::Font MiniStad((path + "../Resources/MiniStad.hfont").c_str(), &_);
extern Heatforge::Font ScoreStad;
Heatforge::Font ScoreStad((path + "../Resources/ScoreStad.hfont").c_str(), &_);
extern Heatforge::Text label;
Heatforge::Text label(L"abcdefghijklmnopqrstuvwxyz0123456789:-+.!?%=&", &MiniStad, 259, 223);

extern Heatforge::Spritesheet wallSprites;
Heatforge::Spritesheet wallSprites = _.LoadSpritesheet((path + "../Resources/walls.png").c_str(), 20, 240);
extern Heatforge::Spritesheet background;
Heatforge::Spritesheet background = _.LoadSpritesheet((path + "../Resources/background.png").c_str(), 280, 240);
extern Heatforge::Spritesheet playerSprites;
Heatforge::Spritesheet playerSprites = _.LoadSpritesheet((path + "../Resources/player.png").c_str(), 11, 14);

extern Heatforge::Vector2 playerPosition;
Heatforge::Vector2 playerPosition(100, 100);
extern Heatforge::Entity player;
Heatforge::Entity player(&playerSprites, &playerPosition);

extern void Debug();
extern void DrawPass();
extern void Clear();
void Clear()
{
    _.Clear();
}
extern void Update();
void Update()
{
    _.Update();
}