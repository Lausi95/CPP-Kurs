#ifndef HALLOWELT_TILE_H
#define HALLOWELT_TILE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"

// A Tile is a rectangle shaped Part of a Texture.
class Tile {
public:
    // Creates a new Tile based on a texure with a rectangular partition of it.
    Tile(Texture *texture, int posX, int posY, int width, int height);

    // gets the pointer to a SDL_Rect objekt, that represents the partition of the tile on the Texture.
    SDL_Rect* getRekt();

    // gets the pointer to the texure of the Tile.
    Texture* getTexture();

private:
    Texture *texture;
    SDL_Rect rect;
};


#endif
