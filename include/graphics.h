#pragma once

#include <string>

struct SDL_Texture;
struct SDL_Renderer;

/**
 * Loads the surface pointed to by path.
 * @return the surface loaded
 */
SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);