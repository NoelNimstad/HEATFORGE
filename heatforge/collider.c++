#include "collider.h"

bool Heatforge::Collider::CalculateCollisions(std::vector<Heatforge::Collider*> * col)
{
    colliders.clear();

    for(const auto & c : (*col))
    {
        if(position -> x < c -> position -> x + c -> size -> x
        && position -> x + size -> x > c -> position -> x
        && position -> y < c -> position -> y + c -> size -> y
        && position -> y + size -> y > c -> position -> y)
        {
            isColliding = true;
        } else 
        {
            isColliding = false;
        }
    }

    return isColliding;
}