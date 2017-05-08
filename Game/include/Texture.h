//
// Created by tom on 05.05.17.
//

#ifndef HALLOWELT_TEXTURE_H
#define HALLOWELT_TEXTURE_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
public:
    Texture(const char *source);

    SDL_Surface *getSurface();

private:
    SDL_Surface *textureSurface;
};


#endif //HALLOWELT_TEXTURE_H
