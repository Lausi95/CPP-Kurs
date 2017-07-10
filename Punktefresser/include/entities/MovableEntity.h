#ifndef PUNKTEFRESSER_MOVABLEENTITY_H
#define PUNKTEFRESSER_MOVABLEENTITY_H

#include "stdafx.h"

class MovableEntity : public Entity {
public:
    MovableEntity(float x, float y);
    virtual void changeDirection(Direction direction) = 0;
};

#endif
