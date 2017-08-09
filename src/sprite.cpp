#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"
#include "sprite.h"

Sprite::Sprite(std::string path, SDL_Renderer* renderer, int srcX, int srcY, int srcWidth, int srcHeight, int x, int y) {
    SDL_Rect srcRect {srcX, srcY, srcWidth, srcHeight};
    src = srcRect;

    location = Vector2(x, y);
    spritesheet = loadTexture(renderer, path); 
}

Sprite::~Sprite() {
    SDL_DestroyTexture(spritesheet);
}

void Sprite::update(float timeToUpdate) {}

void Sprite::draw(SDL_Renderer* renderer) {
    SDL_Rect destRect {static_cast<int>(location.x), static_cast<int>(location.y), src.w, src.h};
    SDL_RenderCopy(renderer, spritesheet, &src, &destRect);
}