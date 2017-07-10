#ifndef PUNKTEFRESSER_STATICENTITY_H
#define PUNKTEFRESSER_STATICENTITY_H

#include <Tile.h>
#include <Entity.h>

class StaticEntity : public Entity {
private:
    Tile* tile;

public:
    StaticEntity(float x, float y, Tile* tile) : Entity(x, y) {
        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }
};

#endif //PUNKTEFRESSER_STATICENTITY_H