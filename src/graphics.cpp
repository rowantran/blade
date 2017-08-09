#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "graphics.h"

SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = NULL;

    if (surface == NULL) {
        std::cout << "Could not load image " << path << "! Error: " << SDL_GetError() << std::endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, surface);

        if (texture == NULL) {
            std::cout << "Could not create texture! Error: " << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface(surface);
    }

    return texture;
}