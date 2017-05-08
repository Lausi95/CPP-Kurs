//
// Created by tom on 05.05.17.
//

#include "include/Texture.h"

Texture::Texture(const char *source) {
    this->textureSurface = IMG_Load(source);
}

SDL_Surface *Texture::getSurface() {
    return this->textureSurface;
}
