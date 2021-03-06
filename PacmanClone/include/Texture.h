#ifndef HALLOWELT_TEXTURE_H
#define HALLOWELT_TEXTURE_H

#include <SDL2/SDL_surface.h>
#include <memory>

using surface_ptr = std::shared_ptr<SDL_Surface>;

// A Basic class for holding a Texture loaded as a PNG.
class Texture {
public:
    // creates a new texure with the PNG file of "source".
    Texture(const char *source);

    // gets a SDL_Surface pointer to the texure.
    surface_ptr getSurface();

private:
    surface_ptr textureSurface;
};

#endif
