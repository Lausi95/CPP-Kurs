#ifndef PUNKTEFRESSER_MOVABLEENTITY_H
#define PUNKTEFRESSER_MOVABLEENTITY_H

class MovableEntity : public Entity {
    Direction currentDirection;

public:
    MovableEntity(float x, float y, Direction initialDirection);

    Direction getDirection();

    // changes the Direction
    void changeDirection(Direction newDirection);

    // event function, gets called, if the direction is changed
    virtual void directionChanged(Direction direction) = 0;

    // lets the entity move in a defined way
    virtual void move(LevelMap &levelMap) = 0;
};

#endif
