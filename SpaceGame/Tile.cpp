//
// Created by tom on 05.05.17.
//

#include "include/Tile.h"

Tile::Tile(Texture *texture, int posX, int posY, int width, int height) {
    this->texture = texture;
    this->rect.x = posX;
    this->rect.y = posY;
    this->rect.w = width;
    this->rect.h = height;
}

SDL_Rect *Tile::getRekt() {
    return &this->rect;
}

Texture *Tile::getTexture() {
    return this->texture;
}
