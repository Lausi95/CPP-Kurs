//
// Created by tom on 05.05.17.
//

#include "Tile.h"

Tile::Tile(Texture_SPTR texture, int posX, int posY, int width, int height) {
    this->texture = Texture_SPTR(texture);
    this->rect.x = posX;
    this->rect.y = posY;
    this->rect.w = width;
    this->rect.h = height;
}

SDL_Rect *Tile::getRekt() {
    return &this->rect;
}

Texture_SPTR Tile::getTexture() {
    return this->texture;
}
