#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#include "blade.h"
#include "graphics.h"
#include "settings.h"
#include "timer.h"

Blade::Blade() : 
window((SDL_Init(SDL_INIT_EVERYTHING), SDL_CreateWindow("Blade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, settings::SCREEN_WIDTH, settings::SCREEN_HEIGHT, SDL_WINDOW_SHOWN))),
renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)),
player(renderer, 200, 200),
running(true) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}


void Blade::gameLoop() {
    SDL_Event e;
    Timer timer;
    while (running) {
        timer.start();

        // While there is a pending event
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_a:
                    player.moveLeft();
                    break;

                    case SDLK_d:
                    player.moveRight();
                    break;
                }
            } else if (e.type == SDL_KEYUP) {
                player.stop();
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                switch (e.button.button) {
                    case SDL_BUTTON_LEFT:
                    break;

                    case SDL_BUTTON_RIGHT:
                    break;
                }
            }
        }

        int frameTicks = timer.getTicks();
        if (frameTicks < settings::SCREEN_TICKS_PER_FRAME) {
            SDL_Delay(settings::SCREEN_TICKS_PER_FRAME - frameTicks);
            frameTicks = settings::SCREEN_TICKS_PER_FRAME;
        }

        player.update(frameTicks);

        SDL_RenderClear(renderer);

        player.draw(renderer); 

        SDL_RenderPresent(renderer);
    }
}

Blade::~Blade() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit(); 
}