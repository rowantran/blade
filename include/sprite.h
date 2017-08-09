#pragma once

#include <SDL2/SDL.h>

#include <string>

#include "vector2.h"

struct SDL_Renderer;
struct SDL_Texture;

class Sprite {
    public:
        Sprite(std::string path, SDL_Renderer* renderer, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y);

        virtual ~Sprite();

        virtual void update(float timeToUpdate);
        void draw(SDL_Renderer* renderer);

    protected:
        Vector2 location;
        SDL_Texture* spritesheet;

    private:
        SDL_Rect src;
};