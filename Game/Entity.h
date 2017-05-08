//
// Created by tom on 08.05.17.
//

#ifndef HALLOWELT_ENTITY_H
#define HALLOWELT_ENTITY_H

#include "Tile.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
public:
    Entity(int x, int y, int width, int height);

    virtual Tile* getTile() = 0;

    SDL_Rect* getRekt();

private:
    SDL_Rect rect;
};


#endif //HALLOWELT_ENTITY_H
