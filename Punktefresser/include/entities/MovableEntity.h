#ifndef PUNKTEFRESSER_MOVABLEENTITY_H
#define PUNKTEFRESSER_MOVABLEENTITY_H

class MovableEntity : public Entity {
    Direction currentDirection;

public:
    MovableEntity(float x, float y, Direction initialDirection);

    Direction getDirection();

    void changeDirection(Direction newDirection);

    virtual void directionChanged(Direction direction) = 0;
    virtual void move(LevelMap &levelMap) = 0;
};

#endif
