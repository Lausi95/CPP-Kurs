#include "stdafx.h"

Pacman::Pacman(float x, float y, PacmanTiles *tiles) : MovableEntity(x, y, Direction::Right) {
    this->tiles = tiles;
    this->directionBuffer = Direction::Right;

    this->mouthClosed = false;
    this->currentTile = tiles->lookingRightMouthOpen;
    this->currentMouthClosedTile = tiles->lookingRightMouthClosed;
    this->currentMouthOpenedTile = tiles->lookingRightMouthOpen;
}

Tile *Pacman::getTile() {
    return currentTile;
}

void Pacman::setDirectionBuffer(Direction direction) {
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
    if(stepsTaken == 20) {
        mouthClosed = !mouthClosed;
        stepsTaken = 0;
        setCurrentMouthStateTile();
    }

    switch(getDirection()) {
        case Direction::Up:
            setY(getY() - velocity);
            break;
        case Direction::Down:
            setY(getY() + velocity);
            break;
        case Direction::Left:
            setX(getX() - velocity);
            break;
        case Direction::Right:
            setX(getX() + velocity);
            break;
    }
}

void Pacman::directionChanged(Direction direction) {
    updateMouthStateTilesAccordingToDirection(direction);
    setCurrentMouthStateTile();
}

void Pacman::updateMouthStateTilesAccordingToDirection(const Direction &direction) {
    if (direction == Direction::Up) {
        currentMouthClosedTile = tiles->lookingUpMouthClosed;
        currentMouthOpenedTile = tiles->lookingUpMouthOpen;
    }
    if (direction == Direction::Down) {
        currentMouthClosedTile = tiles->lookingDownMouthClosed;
        currentMouthOpenedTile = tiles->lookingDownMouthOpen;
    }
    if (direction == Direction::Left) {
        currentMouthClosedTile = tiles->lookingLeftMouthClosed;
        currentMouthOpenedTile = tiles->lookingLeftMouthOpen;
    }
    if (direction == Direction::Right) {
        currentMouthClosedTile = tiles->lookingRightMouthClosed;
        currentMouthOpenedTile = tiles->lookingRightMouthOpen;
    }
}

void Pacman::setCurrentMouthStateTile() {
    if (mouthClosed)
        currentTile = currentMouthClosedTile;
    else
        currentTile = currentMouthOpenedTile;
}
