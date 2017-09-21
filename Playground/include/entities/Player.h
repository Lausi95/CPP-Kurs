#ifndef PLAYGROUND_PLAYER_H
#define PLAYGROUND_PLAYER_H

#include <array>
#include <Entity.h>

enum class LookingDirection {
    Right,
    Left
};

class Player : public Entity {
    std::array<Tile*, 2> _tiles;
    LookingDirection _lookingDirection;

    float _vx;
    float _vy;
    bool _canJump;

public:
    Player(std::array<Tile*, 2> tiles, float x, float y, int width, int height);
    Tile* getTile();
    void setLookingDirection(LookingDirection lookingDirection);

    bool canJump();
    void enableJump();
    void jump();

    void setVx(float vx);
    void setVy(float vy);
    void addVy(float dvy);

    void update();
};

#endif //PLAYGROUND_PLAYER_H
