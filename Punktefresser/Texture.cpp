#include "Texture.h"
#include "logging.h"

Texture::Texture(const char *source) {
    std::stringstream ss;
    ss << "Loading Texture \"" << source << "\"";
    INFO(ss)

    this->textureSurface = IMG_Load(source);

    std::stringstream ss2;
    ss2 << "null: \"" << (this->textureSurface == NULL) << "\"";
    INFO(ss2);
}

SDL_Surface *Texture::getSurface() {
    return this->textureSurface;
}
