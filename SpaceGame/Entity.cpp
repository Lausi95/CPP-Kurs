#include "Entity.h"

Entity::Entity(float x, float y) {
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

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}

void Entity::setX(float x) {
    this->x = x;
}

void Entity::setY(float y) {
    this->y = y;
}

bool Entity::pointInside(int x, int y) {
    return x > getLeft() && x < getRight() && y > getTop() && y < getBottom();
}