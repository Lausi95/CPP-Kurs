#ifndef PUNKTEFRESSER_ENEMY_H
#define PUNKTEFRESSER_ENEMY_H

#include "Tile.h"
#include "MovableEntity.h"

class Enemy : public MovableEntity {
public:
    Enemy(float x, float y, Tile* tile);

    Tile* getTile();
    void changeDirection(Direction direction);
    void move(LevelMap &levelMap);

private:
    Tile* tile;
};

#endif //PUNKTEFRESSER_ENEMY_H
