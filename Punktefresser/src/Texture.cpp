#include "Texture.h"
#include "logging.h"
#include <SDL2/SDL_image.h>

Texture::Texture(const char *source) {
    std::stringstream ss;
    ss << "Loading Texture \"" << source << "\"";
    INFO(ss)

    this->textureSurface = IMG_Load(source);
}

SDL_Surface *Texture::getSurface() {
    return this->textureSurface;
}
