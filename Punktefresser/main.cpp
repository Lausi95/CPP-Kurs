#include <LevelMap.h>
#include "stdafx.h"

Texture mainTexture("assets/tiles.png");

Tile tilePlayerLookingTopMouthOpen(&mainTexture, 128+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingBotMouthOpen(&mainTexture, 96+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingLeftMouthOpen(&mainTexture, 128+1, 0+1, 32-1, 32-1);
Tile tilePlayerLookingRightMouthOpen(&mainTexture, 96+1, 0+1, 32-1, 32-1);

Tile tilePlayerLookingTopMouthClosed(&mainTexture, 224+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingBotMouthClosed(&mainTexture, 192+1, 32+1, 32-1, 32-1);
Tile tilePlayerLookingLeftMouthClosed(&mainTexture, 224+1, 0+1, 32-1, 32-1);
Tile tilePlayerLookingRightMouthClosed(&mainTexture, 192+1, 0+1, 32-1, 32-1);

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
    Up,
    Down,
    Left,
    Right
};

class Pacman : public Entity {

public:
    Pacman(float x, float y) : Entity(x, y) {
        this->currentTile = &tilePlayerLookingRightMouthOpen;
        this->currentDirection = Direction::Right;
        this->directionBuffer = Direction::Right;
    }

    Tile* getTile() {
        return currentTile;
    }

    void setNextDirection(Direction direction) {
        this->directionBuffer = direction;
    }

    void tryApplyDirection(LevelMap& levelMap) {
        if (directionBuffer != currentDirection) {
            if (canMoveToOppositeDirection())
                changeDirection(directionBuffer);
            else if (directionBuffer == Direction::Up && canMoveUp(levelMap))
                changeDirection(directionBuffer);
            else if (directionBuffer == Direction::Down && canMoveDown(levelMap))
                changeDirection(directionBuffer);
            else if (directionBuffer == Direction::Left && canMoveLeft(levelMap))
                changeDirection(directionBuffer);
            else if (directionBuffer == Direction::Right && canMoveRight(levelMap))
                changeDirection(directionBuffer);
        }
    }

    bool canMoveToOppositeDirection() {
        return
            currentDirection == Direction::Up && directionBuffer == Direction::Down ||
            currentDirection == Direction::Down && directionBuffer == Direction::Up ||
            currentDirection == Direction::Left && directionBuffer == Direction::Right ||
            currentDirection == Direction::Right && directionBuffer == Direction::Left;
    }

    bool canMoveUp(LevelMap& map) {
        int x = (int)getX();
        int y = (int)getY();
        if (x % 32 == 0 && y % 32 == 0) {
            int nx = x / 32;
            int ny = y / 32 - 1;
            return map(nx, ny) != Field::WALL;
        }
        return false;
    }

    bool canMoveDown(LevelMap& map) {
        int x = (int)getX();
        int y = (int)getY();
        if (x % 32 == 0 && y % 32 == 0) {
            int nx = x / 32;
            int ny = y / 32 + 1;
            return map(nx, ny) != Field::WALL;
        }
        return false;
    }

    bool canMoveLeft(LevelMap& map) {
        int x = (int)getX();
        int y = (int)getY();
        if (x % 32 == 0 && y % 32 == 0) {
            int nx = x / 32 - 1;
            int ny = y / 32;
            return map(nx, ny) != Field::WALL;
        }
        return false;
    }

    bool canMoveRight(LevelMap& map) {
        int x = (int)getX();
        int y = (int)getY();
        if (x % 32 == 0 && y % 32 == 0) {
            int nx = x / 32 + 1;
            int ny = y / 32;
            return map(nx, ny) != Field::WALL;
        }
        return false;
    }

    void changeDirection(Direction direction) {

        switch(direction) {

<<<<<<< Updated upstream
            case Direction::DIR_TOP:
                if(mouthClosed) {
                    currentTile = &tilePlayerLookingTopMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingTopMouthOpen;
                }
                break;

            case Direction::DIR_BOT:
                if(mouthClosed) {
                    currentTile = &tilePlayerLookingBotMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingBotMouthOpen;
                }
                break;

            case Direction::DIR_LEFT:
                if(mouthClosed) {
                    currentTile = &tilePlayerLookingLeftMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingLeftMouthOpen;
                }
                break;

            case Direction::DIR_RIGHT:
                if(mouthClosed) {
                    currentTile = &tilePlayerLookingRightMouthClosed;
                }
                else {
                    currentTile = &tilePlayerLookingRightMouthOpen;
                }
=======
            case Direction::Up:
                currentTile = &tilePlayerLookingTopMouthOpen;
                break;

            case Direction::Down:
                currentTile = &tilePlayerLookingBotMouthOpen;
                break;

            case Direction::Left:
                currentTile = &tilePlayerLookingLeftMouthOpen;
                break;

            case Direction::Right:
                currentTile = &tilePlayerLookingRightMouthOpen;
>>>>>>> Stashed changes
                break;
        }

        currentDirection = direction;
    }

    void move() {

        stepsTaken++;
        bool needReassignTile = false;
        if(stepsTaken == 20) {
            mouthClosed = !mouthClosed;
            stepsTaken = 0;
            needReassignTile = true;
        }

        switch(currentDirection) {

<<<<<<< Updated upstream
            case Direction::DIR_TOP:
                setY(getY() - velocity);
=======
            case Direction::Up:
                setY(getY() - 1);
>>>>>>> Stashed changes
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingTopMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingTopMouthOpen;
                    }
                }
                break;

<<<<<<< Updated upstream
            case Direction::DIR_BOT:
                setY(getY() + velocity);
=======
            case Direction::Down:
                setY(getY() + 1);
>>>>>>> Stashed changes
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingBotMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingBotMouthOpen;
                    }
                }
                break;

<<<<<<< Updated upstream
            case Direction::DIR_LEFT:
                setX(getX() - velocity);
=======
            case Direction::Left:
                setX(getX() - 1);
>>>>>>> Stashed changes
                if(needReassignTile) {
                    if(mouthClosed) {
                        currentTile = &tilePlayerLookingLeftMouthClosed;
                    }
                    else {
                        currentTile = &tilePlayerLookingLeftMouthOpen;
                    }
                }
                break;

<<<<<<< Updated upstream
            case Direction::DIR_RIGHT:
                setX(getX() + velocity);
=======
            case Direction::Right:
                setX(getX() + 1);
>>>>>>> Stashed changes
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
    int velocity = 3;

    bool mouthClosed = false;

    Direction directionBuffer;
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
std::vector <Enemy*> enemies;

void renderMap(Window window, LevelMap levelMap) {

    for(int row = 0; row < levelMap.getRowCount(); row++) {
        for(int column = 0; column < levelMap.getColumnCount(); column++) {

            Entity* entity;

            //drawing background in every case (transperant fruits etc...)
            entity = new Background(column * 32, row *32, &tileNormalBackground);
            window.renderEntity(entity);

            Field field = levelMap.getFieldAt(column, row);
            switch(field) {

                case Field::EMPTY:
                    entity = new Background(column * 32, row *32, &tilePoint);
                    break;

                case Field::WALL:
                    entity = new Wall(column * 32, row *32, &tileWall);
                    break;

                case Field::FRUIT:
                    entity = new Fruit(column * 32, row *32, &tileFruitMelon);
                    break;

                case Field::PLAYER:
                    if(pacman == NULL) {
                        pacman = new Pacman(column * 32, row *32);
                    }
                    levelMap.setFieldAt(column, row, Field::EMPTY);
                    break;

                case Field::ENEMY:
                    enemies.push_back(new Enemy(column * 32, row *32, &tileEnemy));
                    levelMap.setFieldAt(column, row, Field::EMPTY);
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

    while (running) {

        // render entities
        //window.renderEntity(pacman);

        renderMap(window, levelMap);

        window.renderEntity(pacman);

        for(Enemy* enemy : enemies) {
            window.renderEntity(enemy);
        }

        // input
        while (inputHandler.pollEvent()) {

            if (inputHandler.isKeyPressed(SDLK_w)) {
                pacman->setNextDirection(Direction::Up);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                pacman->setNextDirection(Direction::Down);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                pacman->setNextDirection(Direction::Left);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                pacman->setNextDirection(Direction::Right);
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }
        // update

<<<<<<< Updated upstream
        pacman->move();
=======
        pacman->tryApplyDirection(levelMap);
        waitingTimePacman--;
        if(waitingTimePacman == 0) {
            pacman->move();
            waitingTimePacman = MAX_WAITING_TIME_PACMAN;
        }
>>>>>>> Stashed changes

        window.update();
        timer.sleep(8);
        timer.update();
    }

    return 0;
}
