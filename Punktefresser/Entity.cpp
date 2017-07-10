#include "Entity.h"

Entity::Entity(int x, int y) {
    this->rect = SDL_Rect();
    this->x = x;
    this->y = y;
}

SDL_Rect *Entity::getRekt() {
    rect.x = (int)x;
    rect.y = (int)y;
    return &rect;
}

int Entity::getWidth() {
    return getTile()->getRekt()->w;
}

int Entity::getHeight() {
    return getTile()->getRekt()->h;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setX(int x) {
    this->x = x;
}

void Entity::setY(int y) {
    this->y = y;
}

bool Entity::pointInside(int x, int y) {
    return x > getLeft() && x < getRight() && y > getTop() && y < getBottom();
}

int Entity::getX(int divisor) const {
    return getX() / divisor;
}

int Entity::getY(int divisor) const {
    return getY() / divisor;
}

bool Entity::isOnTilePoint() const {
    return getX() % TILE_WIDTH == 0 && getY() % TILE_HEIGHT == 0;
}
