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
    Entity(int x, int y);

    virtual Tile* getTile() = 0;

    SDL_Rect* getRekt();

    int getWidth();
    int getHeight();
    int getX();
    int getY();

    void setX(int x);
    void setY(int y);

private:
    SDL_Rect rect;
};


#endif //HALLOWELT_ENTITY_H
