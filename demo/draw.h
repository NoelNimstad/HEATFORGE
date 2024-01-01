#pragma once
#include "global.h"

void DrawPass()
{
    background.Draw();
    player.Draw();

    wallSprites.SelectSprite(0);
    wallSprites.SetPosition(0, 0);
    wallSprites.Draw();
    wallSprites.SelectSprite(1);
    wallSprites.SetPosition(300, 0);
    wallSprites.Draw();

    std::wstring scoreString = std::to_wstring(score);
    std::vector<int> scoreInts = ScoreStad.ConvertStringToIntArray(scoreString);
    ScoreStad.Draw(&scoreInts, &scorePosition);
}