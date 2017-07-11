#ifndef HALLOWELT_ENTITY_H
#define HALLOWELT_ENTITY_H

#define TILE_WIDTH 32
#define TILE_HEIGHT 32

#include "Tile.h"
#include "LevelMap.h"

// A Entity is a renderable Objekt. It has a Position and dimension.
// The dimension is equal to the tile that is renderd with the Entity.
class Entity {
public:
    // Created a new entity with a position.
    Entity(int x, int y);

    // Gets the tile to renderEntity the entity and determine its width and height.
    virtual Tile* getTile() = 0;

    // gets the renderEntity rectangle of the entity.
    SDL_Rect* getRekt();

    // gets the width of the entity.
    int getWidth();

    // gets the height of the entity.
    int getHeight();

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
    SDL_Rect rect;

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
