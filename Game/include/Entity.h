#ifndef HALLOWELT_ENTITY_H
#define HALLOWELT_ENTITY_H

#include "Tile.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// A Entity is a renderable Objekt. It has a Position and dimension.
// The dimension is equal to the tile that is renderd with the Entity.
class Entity {
public:
    // Created a new entity with a position.
    Entity(float x, float y);

    // Gets the tile to render the entity and determine its width and height.
    virtual Tile* getTile() = 0;

    // gets the render rectangle of the entity.
    SDL_Rect* getRekt();

    // gets the width of the entity.
    int getWidth();

    // gets the height of the entity.
    int getHeight();

    // gets the x-Position of the entity.
    float getX();

    // gets the y-Position of the entity.
    float getY();

    // gets the left position of the entity.
    inline float getLeft() { return getX(); }

    // gets the right position of the entity.
    inline float getRight() { return getX() + getWidth(); }

    // gets the top position of the entity.
    inline float getTop() { return getY(); }

    // gets the bottom position of the entity.
    inline float getBottom() { return getY() + getHeight(); }

    // sets the x-Position of the entity.
    void setX(float x);

    // sets the y-Position of the entity.
    void setY(float y);

    // sets the left position of the entity.
    inline void setLeft(float left) { setX(left); }

    // sets the right position of the entity.
    inline void setRight(float right) { setX(right - getWidth()); }

    // sets the top position of the entity.
    inline void setTop(float top) { setY(top); }

    // sets the bottom position of the entity.
    inline void setBottom(float bottom) { setY(bottom - getHeight()); }

    bool pointInside(int x, int y);

private:
    SDL_Rect rect;

    float x;
    float y;
};


#endif
