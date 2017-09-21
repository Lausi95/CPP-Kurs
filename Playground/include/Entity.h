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
    int getWidth();
    int getHeight();
    Rectangle* getRectangle();

    void setX(float x);
    void setY(float y);

    float getBottom();
    void setBottom(float bottom);

    float getTop();
    void setTop(float top);

    float getLeft();
    void setLeft(float left);

    float getRight();
    void setRight(float right);

    virtual Tile* getTile() = 0;
};

#endif //PLAYGROUND_ENTITY_H
