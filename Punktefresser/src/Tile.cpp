//
// Created by tom on 05.05.17.
//

#include "Tile.h"

Tile::Tile(texture_ptr texture, int posX, int posY, int width, int height) {
    this->texture = texture_ptr(texture);
    this->rect = rect_ptr(new SDL_Rect);
    this->rect->x = posX;
    this->rect->y = posY;
    this->rect->w = width;
    this->rect->h = height;
}

rect_ptr Tile::getRekt() {
    return rect;
}

texture_ptr Tile::getTexture() {
    return this->texture;
}
