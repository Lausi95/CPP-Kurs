#ifndef HALLOWELT_TILE_H
#define HALLOWELT_TILE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"

class Tile {
public:
    Tile(Texture *texture, int posX, int posY, int width, int height);

    SDL_Rect* getRekt();
    Texture* getTexture();

private:
    Texture *texture;
    SDL_Rect rect;
};


#endif //HALLOWELT_TILE_H
