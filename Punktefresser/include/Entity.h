#ifndef HALLOWELT_ENTITY_H
#define HALLOWELT_ENTITY_H

#define TILE_WIDTH 32
#define TILE_HEIGHT 32

#include "Tile.h"

// A Entity is a renderable Objekt. It has a Position and dimension.
// The dimension is equal to the tile that is renderd with the Entity.
class Entity {
public:
    // Created a new entity with a position.
    Entity(int x, int y);

    // Gets the tile to renderEntity the entity and determine its width and height.
    virtual Tile* getTile() = 0;

    // gets the renderEntity rectangle of the entity.
    SDL_Rect* getRekt();

    // gets the width of the entity.
    int getWidth();

    // gets the height of the entity.
    int getHeight();

    // gets the x-Position of the entity.
    int getX() const;
    int getX(int divisor) const;

    // gets the y-Position of the entity.
    int getY() const;
    int getY(int divisor) const;

    // gets the left position of the entity.
    inline int getLeft() { return getX(); }

    // gets the right position of the entity.
    inline int getRight() { return getX() + getWidth(); }

    // gets the top position of the entity.
    inline int getTop() { return getY(); }

    // gets the bottom position of the entity.
    inline int getBottom() { return getY() + getHeight(); }

    // sets the x-Position of the entity.
    void setX(int x);

    // sets the y-Position of the entity.
    void setY(int y);

    // sets the left position of the entity.
    inline void setLeft(int left) { setX(left); }

    // sets the right position of the entity.
    inline void setRight(int right) { setX(right - getWidth()); }

    // sets the top position of the entity.
    inline void setTop(int top) { setY(top); }

    // sets the bottom position of the entity.
    inline void setBottom(int bottom) { setY(bottom - getHeight()); }

    bool pointInside(int x, int y);

    bool isOnTilePoint() const;

private:
    SDL_Rect rect;

    int x;
    int y;
};


#endif
