#include <SDL2/SDL.h>

#include <iostream>

#include "blade.h"
#include "graphics.h"
#include "settings.h"
#include "sprite.h"

Blade::Blade() : 
window((SDL_Init(SDL_INIT_EVERYTHING), SDL_CreateWindow("Blade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, settings::SCREEN_WIDTH, settings::SCREEN_HEIGHT, SDL_WINDOW_SHOWN))),
surface(SDL_GetWindowSurface(window)), 
player("data/sprites/player.png", surface->format, 0, 0, 64, 64, 200, 200),
running(true) {}


void Blade::gameLoop() {
    SDL_Event e;
    while (this->running) {
        this->player.draw(this->surface); 
        SDL_UpdateWindowSurface(this->window);

        // While there is a pending event
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                this->running = false;
            }
        }
    }

    this->quit();
}

void Blade::quit() {
    SDL_DestroyWindow(this->window);

    SDL_Quit(); 
}