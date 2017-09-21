#include <Texture.h>

bool sdlImageInitialized = false;

Texture::Texture(const char *file) {
    if (!sdlImageInitialized) {
        IMG_Init(IMG_INIT_PNG);
        sdlImageInitialized = true;
    }

    _file = file;
    _surface = IMG_Load(file);
}

const char *Texture::getFile() {
    return _file;
}

SDL_Surface *Texture::getSurface() {
    return _surface;
}
