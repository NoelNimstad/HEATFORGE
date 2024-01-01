#pragma once
#include "global.h"

Heatforge::Vector2 velocity = _.ZERO;
float direction = 0.1;
void PhysicsPass()
{
    velocity.x = direction * _.delta;
    velocity.y += g * _.delta;
    if(_.GetKey(L" "))
    {
        velocity.y = -0.5;
    }

    playerPosition += velocity;

    if(playerPosition.x > 291 || playerPosition.x < 20)
    {
        playerPosition += !velocity;
        direction *= -1.02;
        score++;
    }
}