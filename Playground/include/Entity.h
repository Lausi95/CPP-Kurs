#ifndef PLAYGROUND_ENTITY_H
#define PLAYGROUND_ENTITY_H

#include <Tile.h>

class Entity {
    Rectangle* _rectangle;

public:
    Entity();
    Entity(float x, float y, int width, int height);
    ~Entity();

    float getX();
    float getY();
    float getWidth();
    float getHeight();
    Rectangle* getRectangle();

    void setX(float x);
    void setY(float y);

    virtual Tile* getTile() = 0;
};

#endif //PLAYGROUND_ENTITY_H
