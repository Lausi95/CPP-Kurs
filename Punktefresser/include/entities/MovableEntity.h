#ifndef PUNKTEFRESSER_MOVABLEENTITY_H
#define PUNKTEFRESSER_MOVABLEENTITY_H

class MovableEntity : public Entity {
public:
    MovableEntity(float x, float y);

    virtual void changeDirection(Direction direction) = 0;
    virtual void move(LevelMap &levelMap) = 0;
};

#endif
