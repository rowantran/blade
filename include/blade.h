#include "player.h"

class Blade {
    public:
        Blade();
        ~Blade();

        /**
         * Begins the game loop. 
         */
        void gameLoop();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        Player player;

        bool running;

        /**
         * Quits the game.
         */
        void quit();
};