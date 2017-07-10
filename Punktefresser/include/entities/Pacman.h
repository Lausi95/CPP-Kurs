#ifndef PUNKTEFRESSER_PACMAN_H
#define PUNKTEFRESSER_PACMAN_H

#include "stdafx.h"

class Pacman : public MovableEntity {

public:
    Pacman(float x, float y) : MovableEntity(x, y) {
        this->currentTile = &tilePlayerLookingRightMouthOpen;
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
                else if (directionBuffer == Direction::Up && nextField(levelMap, nx, ny, Direction::Up) != Field::Wall)
                    changeDirection(directionBuffer);
                else if (directionBuffer == Direction::Down && nextField(levelMap, nx, ny, Direction::Down) != Field::Wall)
                    changeDirection(directionBuffer);
                else if (directionBuffer == Direction::Left && nextField(levelMap, nx, ny, Direction::Left) != Field::Wall)
                    changeDirection(directionBuffer);
                else if (directionBuffer == Direction::Right && nextField(levelMap, nx, ny, Direction::Right) != Field::Wall)
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

            if (nextField(map, nx, ny, currentDirection) == Field::Wall) {
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
                        currentTile = &tilePlayerLookingTopMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingTopMouthOpen;
                    }
                }
                break;

            case Direction::Down:
                setY(getY() + velocity);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingBotMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingBotMouthOpen;
                    }
                }
                break;

            case Direction::Left:
                setX(getX() - velocity);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingLeftMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingLeftMouthOpen;
                    }
                }
                break;

            case Direction::Right:
                setX(getX() + velocity);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingRightMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingRightMouthOpen;
                    }
                }
                break;
        }
    }

private:
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
                    currentTile = &tilePlayerLookingTopMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingTopMouthOpen;
                }
                break;

            case Direction::Down:
                if(mouthClosed) {
                    currentTile = &tilePlayerLookingBotMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingBotMouthOpen;
                }
                break;

            case Direction::Left:
                if(mouthClosed) {
                    currentTile = &tilePlayerLookingLeftMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingLeftMouthOpen;
                }
                break;

            case Direction::Right:
                if(mouthClosed) {
                    currentTile = &tilePlayerLookingRightMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingRightMouthOpen;
                }
                break;
        }

        currentDirection = direction;
    }
};

#endif //PUNKTEFRESSER_PACMAN_H
