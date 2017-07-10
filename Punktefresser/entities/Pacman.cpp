#include "stdafx.h"

Pacman::Pacman(float x, float y, PacmanTiles *tiles) : MovableEntity(x, y) {
    this->tiles = tiles;
    this->currentTile = tiles->lookingRightMountOpen;
    this->currentDirection = Direction::Right;
    this->directionBuffer = Direction::Right;
}

Tile *Pacman::getTile() {
    return currentTile;
}

void Pacman::setNextDirection(Direction direction) {
    this->directionBuffer = direction;
}

void Pacman::tryApplyDirection(LevelMap &levelMap) {
    if (directionBuffer != currentDirection) {
        if (getX() % 32 == 0 && getY() % 32 == 0) {
            int nx = getX() / 32;
            int ny = getY() / 32;

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

bool Pacman::canMoveToOppositeDirection() {
    return
            currentDirection == Direction::Up && directionBuffer == Direction::Down ||
            currentDirection == Direction::Down && directionBuffer == Direction::Up ||
            currentDirection == Direction::Left && directionBuffer == Direction::Right ||
            currentDirection == Direction::Right && directionBuffer == Direction::Left;
}

void Pacman::move(LevelMap &map) {

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

void Pacman::changeDirection(Direction direction) {

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
