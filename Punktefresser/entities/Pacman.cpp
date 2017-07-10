#include "stdafx.h"

Pacman::Pacman(float x, float y, PacmanTiles *tiles) : MovableEntity(x, y, Direction::Right) {
    this->tiles = tiles;
    this->currentTile = tiles->lookingRightMountOpen;
    this->directionBuffer = Direction::Right;
}

Tile *Pacman::getTile() {
    return currentTile;
}

void Pacman::setNextDirection(Direction direction) {
    this->directionBuffer = direction;
}

void Pacman::tryApplyDirection(LevelMap &levelMap) {
    if (shouldChangeDirection(levelMap))
        changeDirection(directionBuffer);
}

bool Pacman::shouldChangeDirection(LevelMap &levelMap) {
    return isInDirectionChangableState() && canChangeDirection(levelMap);
}


bool Pacman::isInDirectionChangableState() {
    bool actualDirectionIsNotBufferedDirection = directionBuffer != getDirection();
    bool standsAtAChangablePoint = getX() % 32 == 0 && getY() % 32 == 0;

    return actualDirectionIsNotBufferedDirection && standsAtAChangablePoint;
}

bool Pacman::canChangeDirection(LevelMap &levelMap) {
    bool directionBufferIsOppositeDirection = oppositeDirection(getDirection()) == directionBuffer;
    bool nextFieldIsNotWall = levelMap.nextField(getX(32), getY(32), directionBuffer) != Field::Wall;

    return directionBufferIsOppositeDirection || nextFieldIsNotWall;
}

void Pacman::move(LevelMap &map) {

    if (getX() % 32 == 0 && getY() % 32 == 0) {
        int nx = getX() / 32;
        int ny = getY() / 32;

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

        if (map.nextField(nx, ny, getDirection()) == Field::Wall) {
            changeDirection(oppositeDirection(getDirection()));
            directionBuffer = getDirection();
        }
    }

    stepsTaken++;
    bool needReassignTile = false;
    if(stepsTaken == 20) {
        mouthClosed = !mouthClosed;
        stepsTaken = 0;
        needReassignTile = true;
    }

    switch(getDirection()) {

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

void Pacman::directionChanged(Direction direction) {
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
}
