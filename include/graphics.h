#pragma once

#include <string>

struct SDL_Surface;
struct SDL_PixelFormat;

/**
 * Loads the surface pointed to by path.
 * @return the surface loaded
 */
SDL_Surface* loadSurface(std::string path, SDL_PixelFormat* format);