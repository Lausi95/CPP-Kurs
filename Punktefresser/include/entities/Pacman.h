#ifndef PUNKTEFRESSER_PACMAN_H
#define PUNKTEFRESSER_PACMAN_H

#include "entities/MovableEntity.h"
#include "Tile.h"

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
    Pacman(float x, float y, PacmanTiles* tiles) : MovableEntity(x, y) {
        this->tiles = tiles;
        this->currentTile = tiles->lookingRightMountOpen;
        this->currentDirection = Direction::Right;
        this->directionBuffer = Direction::Right;
    }

    Tile* getTile() {
        return currentTile;
    }

    void setNextDirection(Direction direction) {
        this->directionBuffer = direction;
    }

    void tryApplyDirection(LevelMap& levelMap) {
        if (directionBuffer != currentDirection) {
            int x = (int) getX();
            int y = (int) getY();
            if (x % 32 == 0 && y % 32 == 0) {
                int nx = x / 32;
                int ny = y / 32;

                if (canMoveToOppositeDirection())
                    changeDirection(directionBuffer);
                else if (directionBuffer == Direction::Up && levelMap.nextField(nx, ny, Direction::Up) != Field::Wall)
                    changeDirection(directionBuffer);
                else if (directionBuffer == Direction::Down && levelMap.nextField(nx, ny, Direction::Down) != Field::Wall)
                    changeDirection(directionBuffer);
                else if (directionBuffer == Direction::Left && levelMap.nextField(nx, ny, Direction::Left) != Field::Wall)
                    changeDirection(directionBuffer);
                else if (directionBuffer == Direction::Right && levelMap.nextField(nx, ny, Direction::Right) != Field::Wall)
                    changeDirection(directionBuffer);
            }
        }
    }

    bool canMoveToOppositeDirection() {
        return
                currentDirection == Direction::Up && directionBuffer == Direction::Down ||
                currentDirection == Direction::Down && directionBuffer == Direction::Up ||
                currentDirection == Direction::Left && directionBuffer == Direction::Right ||
                currentDirection == Direction::Right && directionBuffer == Direction::Left;
    }

    void move(LevelMap& map) {

        int ix = (int) getX();
        int iy = (int) getY();
        if (ix % 32 == 0 && iy % 32 == 0) {
            int nx = ix / 32;
            int ny = iy / 32;

            if (map(nx, ny) == Field::FloorWithPoint) {
                map.setField(nx, ny, Field::Floor);
                INFO("Collected Point")
                // TODO: add point to scoreboard
            }
            if (map(nx, ny) == Field::Fruit) {
                map.setField(nx, ny, Field::Floor);
                INFO("Collected Fruit")
                // TODO: add fruit "buff"? or additional Points?
            }

            if (map.nextField(nx, ny, currentDirection) == Field::Wall) {
                changeDirection(oppositeDirection(currentDirection));
                directionBuffer = currentDirection;
            }
        }

        stepsTaken++;
        bool needReassignTile = false;
        if(stepsTaken == 20) {
            mouthClosed = !mouthClosed;
            stepsTaken = 0;
            needReassignTile = true;
        }

        switch(currentDirection) {

            case Direction::Up:
                setY(getY() - velocity);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = tiles->lookingUpMountClosed;
                    }
                    else {
                        currentTile = tiles->lookingUpMountOpen;
                    }
                }
                break;

            case Direction::Down:
                setY(getY() + velocity);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = tiles->lookingDownMountClosed;
                    }
                    else {
                        currentTile = tiles->lookingDownMountOpen;
                    }
                }
                break;

            case Direction::Left:
                setX(getX() - velocity);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = tiles->lookingLeftMountClosed;
                    }
                    else {
                        currentTile = tiles->lookingLeftMountOpen;
                    }
                }
                break;

            case Direction::Right:
                setX(getX() + velocity);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = tiles->lookingRightMountClosed;
                    }
                    else {
                        currentTile = tiles->lookingRightMountOpen;
                    }
                }
                break;
        }
    }

private:
    PacmanTiles* tiles;
    Tile* currentTile;

    int stepsTaken = 0;
    int velocity = 4;

    bool mouthClosed = false;

    Direction directionBuffer;
    Direction currentDirection;

    void changeDirection(Direction direction) {

        switch(direction) {
            case Direction::Up:
                if(mouthClosed) {
                    currentTile = tiles->lookingUpMountClosed;
                }
                else {
                    currentTile = tiles->lookingUpMountOpen;
                }
                break;

            case Direction::Down:
                if(mouthClosed) {
                    currentTile = tiles->lookingDownMountClosed;
                }
                else {
                    currentTile = tiles->lookingDownMountOpen;
                }
                break;

            case Direction::Left:
                if(mouthClosed) {
                    currentTile = tiles->lookingLeftMountClosed;
                }
                else {
                    currentTile = tiles->lookingLeftMountOpen;
                }
                break;

            case Direction::Right:
                if(mouthClosed) {
                    currentTile = tiles->lookingRightMountClosed;
                }
                else {
                    currentTile = tiles->lookingRightMountOpen;
                }
                break;
        }

        currentDirection = direction;
    }
};

#endif //PUNKTEFRESSER_PACMAN_H
