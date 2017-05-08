//
// Created by tom on 05.05.17.
//

#include "Tile.h"

Tile::Tile(Texture *texture, int posX, int posY, int width, int height) {
    this->texture = texture;
    this->rect.x = posX;
    this->rect.y = posY;
    this->rect.w = width;
    this->rect.h = height;
}

int Tile::getWidth() {
    return this->rect.w;
}

int Tile::getHeight() {
    return this->rect.h;
}

SDL_Rect *Tile::getRekt() {
    return &this->rect;
}

Texture *Tile::getTexture() {
    return this->texture;
}
