#ifndef PUNKTEFRESSER_PACMAN_H
#define PUNKTEFRESSER_PACMAN_H

#include "Tile.h"
#include "entities/MovableEntity.h"

struct PacmanTiles {
    Tile* lookingUpMountOpen;
    Tile* lookingUpMountClosed;

    Tile* lookingDownMountOpen;
    Tile* lookingDownMountClosed;

    Tile* lookingLeftMountOpen;
    Tile* lookingLeftMountClosed;

    Tile* lookingRightMountOpen;
    Tile* lookingRightMountClosed;
};

class Pacman : public MovableEntity {
public:
    Pacman(float x, float y, PacmanTiles* tiles);

    Tile* getTile();

    void setNextDirection(Direction direction);
    void tryApplyDirection(LevelMap& levelMap);
    bool canMoveToOppositeDirection();
    void move(LevelMap& map);

private:
    PacmanTiles* tiles;
    Tile* currentTile;

    int stepsTaken = 0;
    const int velocity = 4;

    bool mouthClosed = false;

    Direction directionBuffer;
    Direction currentDirection;

    void changeDirection(Direction direction);
};

#endif //PUNKTEFRESSER_PACMAN_H
