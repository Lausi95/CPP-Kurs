#include <stdafx.h>


StaticEntity::StaticEntity(float x, float y, Tile *tile) : Entity(x, y) {
    this->tile = tile;
}

Tile *StaticEntity::getTile() {
    return tile;
}

bool StaticEntity::operator==(const StaticEntity &b) const {
    bool xSame = getX() == b.getX();
    bool ySame = getY() == b.getY();
    return xSame && ySame;
}
