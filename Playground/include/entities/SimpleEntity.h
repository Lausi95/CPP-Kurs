#ifndef PLAYGROUND_SIMPLEENTITY_H
#define PLAYGROUND_SIMPLEENTITY_H

#include <Entity.h>

class SimpleEntity : public Entity {
    Tile* _tile;

public:
    float vy = 0;
    bool canJump = false;

    SimpleEntity(Tile* tile, float x, float y) : Entity(x, y, tile->getWidth(), tile->getHeight()) {
        _tile = tile;
    }

    Tile* getTile() {
        return _tile;
    }
};

#endif //PLAYGROUND_SIMPLEENTITY_H
