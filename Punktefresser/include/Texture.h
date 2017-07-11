#ifndef HALLOWELT_TEXTURE_H
#define HALLOWELT_TEXTURE_H

#include <SDL2/SDL_surface.h>
#include <memory>

using SDL_Surface_ptr = std::shared_ptr<SDL_Surface>;

// A Basic class for holding a Texture loaded as a PNG.
class Texture {
public:
    // creates a new texure with the PNG file of "source".
    Texture(const char *source);

    // gets a SDL_Surface pointer to the texure.
    SDL_Surface_ptr getSurface();

private:
    SDL_Surface_ptr textureSurface;
};

#endif
