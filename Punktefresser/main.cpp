#include <LevelMap.h>
#include "stdafx.h"

Texture mainTexture("assets/tiles.png");

Tile tilePlayerLookingTopMouthOpen(&mainTexture, 128+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingBotMouthOpen(&mainTexture, 96+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingLeftMouthOpen(&mainTexture, 128+1, 0+1, 32-1, 32-1);
Tile tilePlayerLookingRightMouthOpen(&mainTexture, 96+1, 0+1, 32-1, 32-1);

Tile tilePlayerLookingTopMouthClosed(&mainTexture, 192+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingBotMouthClosed(&mainTexture, 160+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingLeftMouthClosed(&mainTexture, 192+1, 0+1, 32-1, 32-1);
Tile tilePlayerLookingRightMouthClosed(&mainTexture, 160+1, 0+1, 32-1, 32-1);

Tile tileEnemy(&mainTexture, 160, 0, 32, 32);

Tile tileFruitBanana(&mainTexture, 0, 64, 32, 32);
Tile tileFruitPeach(&mainTexture, 32, 64, 32, 32);
Tile tileFruitGrapes(&mainTexture, 64, 64, 32, 32);
Tile tileFruitApple(&mainTexture, 96, 64, 32, 32);
Tile tileFruitMelon(&mainTexture, 128, 64, 32, 32);
Tile tileFruitPineapple(&mainTexture, 160, 64, 32, 32);
Tile fruitTiles[] = {tileFruitBanana, tileFruitPeach, tileFruitGrapes, tileFruitApple, tileFruitMelon, tileFruitPineapple};

Tile tileWall(&mainTexture, 0, 0, 32, 32);

Tile tilePoint(&mainTexture, 64, 0, 32, 32);
Tile tileNormalBackground(&mainTexture, 64, 32, 32, 32);

enum class Direction {
    DIR_TOP,
    DIR_BOT,
    DIR_LEFT,
    DIR_RIGHT
};

class Pacman : public Entity {

public:
    Pacman(float x, float y) : Entity(x, y) {

        this->currentTile = &tilePlayerLookingRightMouthOpen;
        this->currentDirection = Direction::DIR_RIGHT;
    }

    Tile* getTile() {
        return currentTile;
    }

    void changeDirection(Direction direction) {

        switch(direction) {

            case Direction::DIR_TOP:
                currentTile = &tilePlayerLookingTopMouthOpen;
                break;

            case Direction::DIR_BOT:
                currentTile = &tilePlayerLookingBotMouthOpen;
                break;

            case Direction::DIR_LEFT:
                currentTile = &tilePlayerLookingLeftMouthOpen;
                break;

            case Direction::DIR_RIGHT:
                currentTile = &tilePlayerLookingRightMouthOpen;
                break;
        }

        currentDirection = direction;
    }

    void move() {

        stepsTaken++;
        bool needReassignTile = false;
        if(stepsTaken == 30) {
            mouthClosed = !mouthClosed;
            stepsTaken = 0;
            needReassignTile = true;
        }

        switch(currentDirection) {

            case Direction::DIR_TOP:
                setY(getY() - 1);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingTopMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingTopMouthOpen;
                    }
                }
                break;

            case Direction::DIR_BOT:
                setY(getY() + 1);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingBotMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingBotMouthOpen;
                    }
                }
                break;

            case Direction::DIR_LEFT:
                setX(getX() - 1);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingLeftMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingLeftMouthOpen;
                    }
                }
                break;

            case Direction::DIR_RIGHT:
                setX(getX() + 1);
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingRightMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingRightMouthOpen;
                    }
                }
                break;
        }
    }

private:
    Tile* currentTile;

    int stepsTaken = 0;
    bool mouthClosed = false;
    Direction currentDirection;
};

class Wall : public Entity {

public:
    Wall(float x, float y, Tile* tile) : Entity(x, y) {

        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }

private:
    Tile* tile;
};

class Background : public Entity {

public:
    Background(float x, float y, Tile* tile) : Entity(x, y) {

        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }

private:
    Tile* tile;
};

class Fruit : public Entity {

public:
    Fruit(float x, float y, Tile* tile) : Entity(x, y) {

        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }

private:
    Tile* tile;
};

class Enemy : public Entity {

public:
    Enemy(float x, float y, Tile* tile) : Entity(x, y) {

        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }

private:
    Tile* tile;
};

Pacman* pacman = NULL;

void renderMap(Window window, LevelMap levelMap) {

    for(int row = 0; row < levelMap.getRowCount(); row++) {
        for(int column = 0; column < levelMap.getColumnCount(); column++) {

            Entity* entity;

            Field field = levelMap.fieldAt(column, row);
            switch(field) {

                case Field::EMPTY:
                    entity = new Background(column * 32, row *32, &tileNormalBackground);
                    break;

                case Field::WALL:
                    entity = new Wall(column * 32, row *32, &tileWall);
                    break;

                case Field::PLAYER:
                    if(pacman == NULL) {
                        pacman = new Pacman(column * 32, row *32);
                        entity = pacman;
                    }
                    else {
                        entity = pacman;
                    }
                    break;

                case Field::FRUIT:
                    entity = new Fruit(column * 32, row *32, &tileFruitMelon);
                    break;

                case Field::ENEMY:
                    entity = new Enemy(column * 32, row *32, &tileEnemy);
                    break;
            }

            if(entity != NULL) {
                window.renderEntity(entity);
            }
        }
    }
}

int main(int argc, char** argv) {

    LevelMap levelMap = LevelMap::load("levels/default.lvl");

    srand (time(NULL));

    int levelWidth = levelMap.getColumnCount() * 32;
    int levelHeigth = levelMap.getRowCount() * 32;

    Window window("Punktefresser", levelWidth, levelHeigth);

    InputHandler inputHandler;
    bool running = true;
    Timer timer;

    int MAX_WAITING_TIME_PACMAN = 2;
    int waitingTimePacman = MAX_WAITING_TIME_PACMAN;
    while (running) {

        // render entities
        //window.renderEntity(pacman);

        renderMap(window, levelMap);

        window.renderEntity(pacman);

        // input
        while (inputHandler.pollEvent()) {

            if (inputHandler.isKeyPressed(SDLK_w)) {
                pacman->changeDirection(Direction::DIR_TOP);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                pacman->changeDirection(Direction::DIR_BOT);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                pacman->changeDirection(Direction::DIR_LEFT);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                pacman->changeDirection(Direction::DIR_RIGHT);
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }
        // update

        waitingTimePacman--;
        if(waitingTimePacman == 0) {
            pacman->move();
            waitingTimePacman = MAX_WAITING_TIME_PACMAN;
        }

        window.update();
        timer.sleep(8);
        timer.update();
    }

    return 0;
}
