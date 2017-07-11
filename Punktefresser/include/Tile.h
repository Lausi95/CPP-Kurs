#ifndef HALLOWELT_TILE_H
#define HALLOWELT_TILE_H

#include <Texture.h>
#include <memory>

using Texture_SPTR = std::shared_ptr<Texture>;

// A Tile is a rectangle shaped Part of a Texture.
class Tile {
public:
    // Creates a new Tile based on a texure with a rectangular partition of it.
    Tile(Texture_SPTR texture, int posX, int posY, int width, int height);

    // gets the pointer to a SDL_Rect objekt, that represents the partition of the tile on the Texture.
    SDL_Rect* getRekt();

    // gets the pointer to the texure of the Tile.
    Texture_SPTR getTexture();

private:
    Texture_SPTR texture;
    SDL_Rect rect;
};


#endif
