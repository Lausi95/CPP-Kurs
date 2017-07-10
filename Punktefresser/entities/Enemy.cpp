#include <stdafx.h>


Enemy::Enemy(float x, float y, Tile *tile) : MovableEntity(x, y) {
    this->tile = tile;
}

Tile *Enemy::getTile() {
    return tile;
}

void Enemy::changeDirection(Direction direction) {
}

void Enemy::move(LevelMap &levelMap) {
}
