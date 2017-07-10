#include "stdafx.h"

MovableEntity::MovableEntity(float x, float y, Direction initialDirectiono) : Entity(x, y) {
    this->currentDirection = initialDirectiono;
}

void MovableEntity::changeDirection(Direction newDirection) {
    this->currentDirection = newDirection;
    directionChanged(newDirection);
}

Direction MovableEntity::getDirection() {
    return this->currentDirection;
}
