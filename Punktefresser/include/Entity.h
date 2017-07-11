#ifndef HALLOWELT_ENTITY_H
#define HALLOWELT_ENTITY_H

#include <SDL2/SDL.h>

#include <memory>
#include <Tile.h>
#include <Direction.h>
#include <LevelMap.h>
#include <logging.h>

using tile_ptr = std::shared_ptr<Tile>;

// A Entity is a renderable Objekt. It has a Position and dimension.
// The dimension is equal to the tile that is renderd with the Entity.
class Entity {
public:
    static const int WIDTH = 32;
    static const int HEIGHT = 32;

    // Created a new entity with a position.
    Entity(int x, int y);

    // gets the renderEntity rectangle of the entity.
    SDL_Rect_ptr getRekt();

    // gets the x-Position of the entity.
    int getX() const;
    int getX(int divisor) const;

    // gets the y-Position of the entity.
    int getY() const;
    int getY(int divisor) const;

    // sets the x-Position of the entity.
    void setX(int x);

    // sets the y-Position of the entity.
    void setY(int y);

    bool isOnTilePoint() const;

private:
    SDL_Rect_ptr rect;

    int x;
    int y;
};

class StaticEntity : public Entity {
private:
    Tile* tile;

public:
    StaticEntity(float x, float y, Tile* tile);

    Tile* getTile();

    bool operator ==(const StaticEntity &b) const;
};

class MovableEntity : public Entity {
    Direction currentDirection;

public:
    MovableEntity(float x, float y, Direction initialDirection);

    Direction getDirection();

    // changes the Direction
    void changeDirection(Direction newDirection);

    // event function, gets called, if the direction is changed
    virtual void directionChanged(Direction direction) = 0;

    // lets the entity move in a defined way
    virtual void move(LevelMap &levelMap) = 0;
};

enum class PacmanState {
    MouthOpen,
    MouthClosed
};

PacmanState oppositePacmanState(PacmanState &pacmanState);

struct PacmanTiles {
    Tile* lookingUpMouthOpen;
    Tile* lookingUpMouthClosed;

    Tile* lookingDownMouthOpen;
    Tile* lookingDownMouthClosed;

    Tile* lookingLeftMouthOpen;
    Tile* lookingLeftMouthClosed;

    Tile* lookingRightMouthOpen;
    Tile* lookingRightMouthClosed;
};

class Pacman : public MovableEntity {
public:
    Pacman(float x, float y, PacmanTiles* tiles);

    Tile* getTile();

    void setDirectionBuffer(Direction direction);
    void tryApplyDirection(LevelMap& levelMap);
    void move(LevelMap& map);

private:
    PacmanTiles* tiles;

    PacmanState currentState;
    Tile* currentTile;
    Tile* currentMouthOpenedTile;
    Tile* currentMouthClosedTile;

    int stepsTaken = 0;
    const int velocity = 4;
    Direction directionBuffer;

    void directionChanged(Direction direction);

    bool isInDirectionChangableState();
    bool canChangeDirection(LevelMap &levelMap);
    bool shouldChangeDirection(LevelMap &levelMap);

    void setCurrentMouthStateTile();

    void updateMouthStateTilesAccordingToDirection(const Direction &direction);

    void updateMouthOpenClosedState();
};

class Enemy : public MovableEntity {
public:
    Enemy(float x, float y, Tile* tile);

    Tile* getTile();
    void directionChanged(Direction direction);
    void move(LevelMap &levelMap);

private:
    Tile* tile;
};



#endif
