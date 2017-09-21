#ifndef PLAYGROUND_TILE_H
#define PLAYGROUND_TILE_H

#include <Texture.h>
#include <Rectangle.h>

class Tile {
    Texture* _texture;
    Rectangle* _rectangle;

public:
    Tile(Texture* texture, int x, int y, int width, int height);
    ~Tile();

    int getWidth();
    int getHeight();
    Texture* getTexture();
    Rectangle* getRectangle();
};

#endif //PLAYGROUND_TILE_H
