#include <Player.h>

namespace burnengine {
    Player::Player(std::array<Tile*, 2>& playerLookingDirectionTiles, float x, float y)  : Entity(x, y) {
        this->tiles = playerLookingDirectionTiles;
        this->lookingDirection = LookingDirection::Right;
    }

    Tile* Player::getTile() {
        return tiles[(int)lookingDirection];
    }
}
