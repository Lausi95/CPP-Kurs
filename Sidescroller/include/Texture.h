#ifndef PLAYGROUND_TEXTURE_H
#define PLAYGROUND_TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
    const char* _file;
    SDL_Surface* _surface;

public:
    explicit Texture(const char* file);
    ~Texture();

    const char* getFile();
    SDL_Surface* getSurface();
};

#endif //PLAYGROUND_TEXTURE_H
