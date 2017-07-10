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

const int Entity::getX() const {
    return x;
}

const int Entity::getY() const {
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