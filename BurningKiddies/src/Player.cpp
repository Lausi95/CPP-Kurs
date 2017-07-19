#include <Player.h>

namespace burnengine {
    Player::Player(std::array<Tile*, 2>& playerLookingDirectionTiles, float x, float y)  : Entity(x, y) {
        this->tiles = playerLookingDirectionTiles;
        this->lookingDirection = LookingDirection::Right;
    }

    Tile* Player::getTile() {
        return tiles[(int)lookingDirection];
    }

    void Player::setLookingDirection(LookingDirection direction) {
        this->lookingDirection = direction;
    }

    void Player::update() {
        vx = vx + ax;
        vy = vy + ay;
        setX(getX() + vx);
        setY(getY() + vy);
    }

    float Player::getAY() {
        return ay;
    }
}
