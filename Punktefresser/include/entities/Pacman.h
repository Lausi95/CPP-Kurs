#ifndef PUNKTEFRESSER_PACMAN_H
#define PUNKTEFRESSER_PACMAN_H

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

#endif //PUNKTEFRESSER_PACMAN_H
