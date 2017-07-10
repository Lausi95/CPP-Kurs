#ifndef PUNKTEFRESSER_ENEMY_H
#define PUNKTEFRESSER_ENEMY_H

#include "Tile.h"
#include "MovableEntity.h"

class Enemy : public MovableEntity {
public:
    Enemy(float x, float y, Tile* tile) : MovableEntity(x, y) {
        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }

    void changeDirection(Direction direction) {
    }

    void move() {
    }

private:
    Tile* tile;
};

#endif //PUNKTEFRESSER_ENEMY_H
