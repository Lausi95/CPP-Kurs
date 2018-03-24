#ifndef HALLOWELT_TILE_H
#define HALLOWELT_TILE_H

#include <Texture.h>
#include <memory>

using texture_ptr = std::shared_ptr<Texture>;
using rect_ptr = std::shared_ptr<SDL_Rect>;

// A Tile is a rectangle shaped Part of a Texture.
class Tile {
public:
    // Creates a new Tile based on a texure with a rectangular partition of it.
    Tile(texture_ptr texture, int posX, int posY, int width, int height);

    // gets the pointer to a SDL_Rect objekt, that represents the partition of the tile on the Texture.
    rect_ptr getRekt();

    // gets the pointer to the texure of the Tile.
    texture_ptr getTexture();

private:
    texture_ptr texture;
    rect_ptr rect;
};


#endif
