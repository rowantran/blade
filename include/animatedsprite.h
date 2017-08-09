#pragma once

#include <vector>

#include "sprite.h"

class AnimatedSprite : public Sprite {
    public:
        AnimatedSprite(std::string spritesheet, SDL_Renderer* renderer, int frames, float timeToNextFrame, int startX, int startY, 
        int width, int height, int offset, int x, int y);

        virtual void update(float timeElapsed);
        void draw(SDL_Renderer* renderer);
    
    private:
        void setupFrameSources(int frames, int startX, int startY, int width, int height, int offset);

        float timeSinceLastFrame;
        float timeToNextFrame;

        int frame;
        int frames;
        std::vector<SDL_Rect> frameSources;
};