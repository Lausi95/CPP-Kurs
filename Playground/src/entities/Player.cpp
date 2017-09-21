#include <entities/Player.h>

Player::Player(std::array<Tile*, 2> tiles, float x, float y, int width, int height) : Entity(x, y, width, height) {
    _tiles = tiles;
    _lookingDirection = LookingDirection::Right;
}

Tile* Player::getTile() {
    return _tiles[(int) _lookingDirection];
}

void Player::setLookingDirection(LookingDirection lookingDirection) {
    _lookingDirection = lookingDirection;
}

bool Player::canJump() {
    return _canJump;
}

void Player::enableJump() {
    _canJump = true;
}

void Player::jump() {
    if (_canJump) _vy = -4.0f;
}

void Player::update() {
    getRectangle()->setX(getRectangle()->getX() + _vx);
    getRectangle()->setY(getRectangle()->getY() + _vy);
}

void Player::setVx(float vx) {
    _vx = vx;
    if (vx > 0)
        _lookingDirection = LookingDirection::Right;
    else if (vx < 0)
        _lookingDirection = LookingDirection::Left;
}

void Player::setVy(float vy) {
    _vy = vy;
}

void Player::addVy(float dvy) {
    _vy += dvy;
}
