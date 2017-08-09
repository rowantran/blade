#pragma once

#include "animatedsprite.h"

class Entity : public AnimatedSprite {
    public:
        Entity(std::string spritesheet, SDL_Renderer* renderer, int frames, float timeToNextFrame, int startX,
        int startY, int width, int height, int offset, int x, int y, int health);

    protected:
        int health;
};