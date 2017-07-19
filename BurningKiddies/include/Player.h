#ifndef BURNINGKIDDIES_PLAYER_H
#define BURNINGKIDDIES_PLAYER_H

#include <BurnEngine.h>
#include <array>

namespace burnengine {
    enum class LookingDirection {
        Left,
        Right
    };

    class Player : public burnengine::Entity<float> {
    private:
        std::array<Tile*, 2>  tiles;

    public:
        Player(std::array<Tile*, 2>& playerLookingDirectionTiles, float x, float y);
        LookingDirection lookingDirection;

        Tile* getTile();
    };
}

#endif //BURNINGKIDDIES_PLAYER_H
