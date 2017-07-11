#include <stdafx.h>

Entity::Entity(int x, int y) {
    this->rect = SDL_Rect();
    this->x = x;
    this->y = y;
}

SDL_Rect *Entity::getRekt() {
    rect.x = x;
    rect.y = y;
    return &rect;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setX(int x) {
    this->x = x;
}

void Entity::setY(int y) {
    this->y = y;
}

int Entity::getX(int divisor) const {
    return getX() / divisor;
}

int Entity::getY(int divisor) const {
    return getY() / divisor;
}

bool Entity::isOnTilePoint() const {
    return getX() % WIDTH == 0 && getY() % HEIGHT == 0;
}

StaticEntity::StaticEntity(float x, float y, Tile *tile) : Entity(x, y) {
    this->tile = tile;
}

Tile *StaticEntity::getTile() {
    return tile;
}

bool StaticEntity::operator==(const StaticEntity &b) const {
    bool xSame = getX() == b.getX();
    bool ySame = getY() == b.getY();
    return xSame && ySame;
}

MovableEntity::MovableEntity(float x, float y, Direction initialDirectiono) : Entity(x, y) {
    this->currentDirection = initialDirectiono;
}

void MovableEntity::changeDirection(Direction newDirection) {
    this->currentDirection = newDirection;
    directionChanged(newDirection);
}

Direction MovableEntity::getDirection() {
    return this->currentDirection;
}

Pacman::Pacman(float x, float y, PacmanTiles *tiles) : MovableEntity(x, y, Direction::Right) {
    this->tiles = tiles;
    this->directionBuffer = Direction::Right;

    this->currentState = PacmanState::MouthOpen;
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
    bool standsAtAChangablePoint = isOnTilePoint();

    return actualDirectionIsNotBufferedDirection && standsAtAChangablePoint;
}

bool Pacman::canChangeDirection(LevelMap &levelMap) {
    bool directionBufferIsOppositeDirection = oppositeDirection(getDirection()) == directionBuffer;
    bool nextFieldIsNotWall = levelMap.nextField(getX(32), getY(32), directionBuffer) != Field::Wall;

    return directionBufferIsOppositeDirection || nextFieldIsNotWall;
}

void Pacman::move(LevelMap &map) {

    if (isOnTilePoint()) {
        int xw = getX(WIDTH);
        int yw = getY(HEIGHT);

        if (map(xw, yw) == Field::FloorWithPoint) {
            map.setField(xw, yw, Field::Floor);
            INFO("Collected TILE_POINT")
            // TODO: add point to scoreboard
        }
        if (map(xw, yw) == Field::Fruit) {
            map.setField(xw, yw, Field::Floor);
            INFO("Collected Fruit")
            // TODO: add fruit "buff"? or additional Points?
        }

        if (map.nextField(xw, yw, getDirection()) == Field::Wall) {
            changeDirection(oppositeDirection(getDirection()));
            directionBuffer = getDirection();
        }
    }

    updateMouthOpenClosedState();

    switch (getDirection()) {
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

void Pacman::updateMouthOpenClosedState() {
    if (++stepsTaken == 20) {
        currentState = oppositePacmanState(currentState);
        stepsTaken = 0;
        setCurrentMouthStateTile();
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
    if (currentState == PacmanState::MouthClosed)
        currentTile = currentMouthClosedTile;
    else
        currentTile = currentMouthOpenedTile;
}

PacmanState oppositePacmanState(PacmanState &pacmanState) {
    if (pacmanState == PacmanState::MouthClosed)
        return PacmanState::MouthOpen;
    else
        return PacmanState::MouthClosed;
}


Enemy::Enemy(float x, float y, Tile *tile) : MovableEntity(x, y, Direction::Right) {
    this->tile = tile;
}

Tile *Enemy::getTile() {
    return tile;
}

void Enemy::directionChanged(Direction direction) {
}

void Enemy::move(LevelMap &levelMap) {
}

