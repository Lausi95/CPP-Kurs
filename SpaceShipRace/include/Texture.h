#ifndef HALLOWELT_TEXTURE_H
#define HALLOWELT_TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// A Basic class for holding a Texture loaded as a PNG.
class Texture {
public:
    // creates a new texure with the PNG file of "source".
    Texture(const char *source);

    // gets a SDL_Surface pointer to the texure.
    SDL_Surface *getSurface();

private:
    SDL_Surface *textureSurface;
};


#endif
