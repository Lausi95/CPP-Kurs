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
        float ax = 0;
        float ay = 0;
        float vx = 0;
        float vy = 0;

    public:
        Player(std::array<Tile*, 2>& playerLookingDirectionTiles, float x, float y);
        LookingDirection lookingDirection;

        Tile* getTile();

        void setLookingDirection(LookingDirection direction);

        inline void setAX(float ax) { this->ax = ax; }
        inline void setAY(float ay) { this->ay = ay; }
        inline void setVX(float vx) { this->vx = vx; }
        inline void setVY(float vy) { this->vy = vy; }

        void update();

        float getAY();
    };
}

#endif //BURNINGKIDDIES_PLAYER_H
