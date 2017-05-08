//
// Created by tom on 08.05.17.
//

#include "include/Entity.h"

Entity::Entity(int x, int y) {
    this->rect = SDL_Rect();
    this->rect.x = x;
    this->rect.y = y;
}

SDL_Rect *Entity::getRekt() {
    return &this->rect;
}

int Entity::getWidth() {
    return getTile()->getRekt()->w;
}

int Entity::getHeight() {
    return getTile()->getRekt()->h;
}

int Entity::getX() {
    return rect.x;
}

int Entity::getY() {
    return rect.y;
}

void Entity::setX(int x) {
    this->rect.x = x;
}

void Entity::setY(int y) {
    this->rect.y = y;
}
