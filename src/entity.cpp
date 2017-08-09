#include "entity.h"

Entity::Entity(std::string spritesheet, SDL_Renderer* renderer, int frames, float timeToNextFrame, int startX,
int startY, int width, int height, int offset, int x, int y, int health) : 
AnimatedSprite(spritesheet, renderer, frames, timeToNextFrame, startX, startY, width, height, offset, x, y),
health(health) {}