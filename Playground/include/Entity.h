#ifndef PLAYGROUND_ENTITY_H
#define PLAYGROUND_ENTITY_H

#include <Tile.h>

class Entity {
    Tile* _tile;
    Rectangle* _rectangle;

    bool _tileIsSelfCreated = false;

public:
    Entity(Tile* tile);
    Entity(Tile* tile, float x, float y);
    Entity(Texture* texture, int width, int height, float x, float y);
    ~Entity();

    float getX();
    float getY();
    float getWidth();
    float getHeight();
    Rectangle* getRectangle();

    Tile* getTile();

    void setX(float x);
    void setY(float y);
};

#endif //PLAYGROUND_ENTITY_H
