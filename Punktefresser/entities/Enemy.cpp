#include <stdafx.h>


Enemy::Enemy(float x, float y, Tile *tile) : MovableEntity(x, y, Direction::Right) {
    this->tile = tile;
}

Tile *Enemy::getTile() {
    return tile;
}

void Enemy::directionChanged(Direction direction) {
}

void Enemy::move(LevelMap &levelMap) {
}
