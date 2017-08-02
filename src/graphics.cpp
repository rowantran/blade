#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "graphics.h"

SDL_Surface* loadSurface(std::string path, SDL_PixelFormat* format) {
    SDL_Surface* origSurface = IMG_Load(path.c_str());
    SDL_Surface* optimizedSurface = NULL;

    if (origSurface == NULL) {
        std::cout << "Could not load image " << path << "! Error: " << SDL_GetError() << std::endl;
    } else {
        optimizedSurface = SDL_ConvertSurface(origSurface, format, NULL);
        if (optimizedSurface == NULL) {
            std::cout << "Could not optimize image! Error: " << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface(origSurface);
    }

    return optimizedSurface;
}