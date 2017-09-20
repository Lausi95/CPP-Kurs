#include <Texture.h>

bool sdlImgaeInitialized = false;

Texture::Texture(const char *file) {
    if (!sdlImgaeInitialized) {
        IMG_Init(IMG_INIT_PNG);
        sdlImgaeInitialized = true;
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
