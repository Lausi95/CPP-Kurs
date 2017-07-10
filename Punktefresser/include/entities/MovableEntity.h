#ifndef PUNKTEFRESSER_MOVABLEENTITY_H
#define PUNKTEFRESSER_MOVABLEENTITY_H

#include "Entity.h"

class MovableEntity : public Entity {
public:
    MovableEntity(float x, float y);
    virtual void changeDirection(Direction direction) = 0;
    //virtual void move() = 0;
};

#endif //PUNKTEFRESSER_MOVABLEENTITY_H
