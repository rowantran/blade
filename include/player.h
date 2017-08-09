#pragma once

#include "entity.h"

class Player : public Entity {
    public:
        Player(SDL_Renderer* renderer, float x, float y);

        void moveLeft();
        void moveRight();
        void stop();

        void update(float timeElapsed);

    private:
        float dx, dy;
};