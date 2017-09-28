#ifndef PLAYGROUND_BUTTON_H
#define PLAYGROUND_BUTTON_H

#include <Entity.h>

class Button : public Entity {
    Tile* _tile;

public:

    Button(char* text, Tile* tile, float x, float y) : Entity(x, y, tile->getWidth(), tile->getHeight()) {
        _tile = tile;
    }

    Tile* getTile() {
        return _tile;
    }
};

#endif //PLAYGROUND_BUTTON_H
