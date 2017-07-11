#include <Entity.h>

Entity::Entity(int x, int y) {
    this->rect = SDL_Rect_ptr(new SDL_Rect);
    this->x = x;
    this->y = y;
}

SDL_Rect_ptr Entity::getRekt() {
    this->rect->x = this->x;
    this->rect->y = this->y;
    return this->rect;
}

int Entity::getX() const {
    return this->x;
}

int Entity::getY() const {
    return this->y;
}

void Entity::setX(int x) {
    this->x = x;
}

void Entity::setY(int y) {
    this->y = y;
}

int Entity::getX(int divisor) const {
    return this->getX() / divisor;
}

int Entity::getY(int divisor) const {
    return this->getY() / divisor;
}

bool Entity::isOnTilePoint() const {
    return this->getX() % Entity::WIDTH == 0 && this->getY() % Entity::HEIGHT == 0;
}

StaticEntity::StaticEntity(float x, float y, tile_ptr  &tile) : Entity(x, y) {
    this->tile = tile_ptr(tile);
}

tile_ptr StaticEntity::getTile() {
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
}

Direction MovableEntity::getDirection() {
    return this->currentDirection;
}

Pacman::Pacman(float x, float y, tile_ptr tiles[8]) : MovableEntity(x, y, Direction::Right) {
    this->pacmanTiles = tiles;
    this->directionBuffer = Direction::Right;

    this->currentState = PacmanState::MouthOpen;
}

tile_ptr Pacman::getTile() {
    return getTile(getDirection(), currentState);
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
    }
}

tile_ptr Pacman::getTile(Direction direction, PacmanState state) {
    return pacmanTiles[(int)direction * 2 + (int)state];
}

PacmanState oppositePacmanState(PacmanState &pacmanState) {
    if (pacmanState == PacmanState::MouthClosed)
        return PacmanState::MouthOpen;
    else
        return PacmanState::MouthClosed;
}


Enemy::Enemy(float x, float y, tile_ptr &tile) : MovableEntity(x, y, Direction::Right) {
    this->tile = tile_ptr(tile);
}

tile_ptr Enemy::getTile() {
    return tile;
}

void Enemy::move(LevelMap &levelMap) {
}

