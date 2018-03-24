#include "Texture.h"
#include "logging.h"
#include <SDL2/SDL_image.h>

Texture::Texture(const char *source) {
    std::stringstream ss;
    ss << "Loading Texture \"" << source << "\"";
    INFO(ss)

    this->textureSurface = surface_ptr(IMG_Load(source));
}

surface_ptr Texture::getSurface() {
    return surface_ptr(textureSurface);
}
