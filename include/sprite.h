#pragma once

#include "vector2.h"

struct SDL_PixelFormat;
struct SDL_Surface;

class Sprite {
    public:
        Sprite();
        Sprite(std::string path, SDL_PixelFormat* format, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y);

        ~Sprite();

        virtual void update();
        void draw(SDL_Surface* surface);

        Vector2 dest;
    private:
        SDL_Rect src;
        SDL_Surface* surface;
};