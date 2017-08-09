#include "animatedsprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite(std::string spritesheet, SDL_Renderer* renderer, int frames, float timeToNextFrame, int startX, int startY,
int width, int height, int offset, int x, int y) : 
Sprite(spritesheet, renderer, startX, startY, width, height, x, y),
timeSinceLastFrame(0.0f),
timeToNextFrame(timeToNextFrame),
frame(0),
frames(frames) {
    setupFrameSources(frames, startX, startY, width, height, offset);
}

void AnimatedSprite::setupFrameSources(int frames, int startX, int startY, int width, int height, int offset) {
    for (int i = 0; i < frames; i++) {
        SDL_Rect src;
        src.x = startX + (offset * i) + (width * i);
        src.y = startY;
        src.w = width;
        src.h = height;

        frameSources.push_back(src);
    }
}

void AnimatedSprite::update(float timeElapsed) {
    timeSinceLastFrame += timeElapsed;
    if (timeSinceLastFrame >= timeToNextFrame) {
        timeSinceLastFrame = 0.0f;
        frame++;
        if (frame >= frames) {
            frame = 0;
        }
    }
}

void AnimatedSprite::draw(SDL_Renderer* renderer) {
    SDL_Rect srcRect = frameSources.at(frame);
    SDL_Rect destRect {static_cast<int>(location.x), static_cast<int>(location.y), srcRect.w, srcRect.h};

    SDL_RenderCopy(renderer, spritesheet, &srcRect, &destRect);
}