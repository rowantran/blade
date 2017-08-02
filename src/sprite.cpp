#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"
#include "sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(std::string path, SDL_PixelFormat* format, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y) {
    SDL_Rect srcRect {srcX, srcY, srcWidth, srcHeight};
    this->src = srcRect;

    this->dest = Vector2(x, y);
    this->surface = loadSurface(path, format); 
}

Sprite::~Sprite() {
    SDL_FreeSurface(this->surface);
}

void Sprite::update() {}

void Sprite::draw(SDL_Surface* surface) {
    SDL_Rect destRect {this->dest.x, this->dest.y, this->src.w, this->src.h};
    SDL_BlitSurface(this->surface, &this->src, surface, &destRect);
}