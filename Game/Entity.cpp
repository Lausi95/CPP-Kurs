//
// Created by tom on 08.05.17.
//

#include "Entity.h"

Entity::Entity(int x, int y, int width, int height) {
    this->rect = SDL_Rect();
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = width;
    this->rect.h = height;
}

SDL_Rect *Entity::getRekt() {
    return &this->rect;
}
