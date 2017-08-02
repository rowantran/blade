#include "sprite.h"

class Blade {
    public:
        Blade();

        /**
         * Begins the game loop. 
         */
        void gameLoop();
    private:
        SDL_Window* window;
        SDL_Surface* surface;
        
        Sprite player;

        bool running;

        /**
         * Quits the game.
         */
        void quit();
};