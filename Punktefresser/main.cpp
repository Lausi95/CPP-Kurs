#include <LevelMap.h>
#include "stdafx.h"

Texture mainTexture("assets/tiles.png");

Tile tilePlayerLookingTop(&mainTexture, 128, 32, 32, 32);
Tile tilePlayerLookingBot(&mainTexture, 96, 32, 32, 32);
Tile tilePlayerLookingLeft(&mainTexture, 128, 0, 32, 32);
Tile tilePlayerLookingRight(&mainTexture, 96, 0, 32, 32);

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
    Pacman(float x, float y, Tile* tileTop, Tile* tileBot, Tile* tileLeft, Tile* tileRight) : Entity(x, y) {

        this->tileTop = tileTop;
        this->tileBot = tileBot;
        this->tileLeft = tileLeft;
        this->tileRight = tileRight;

        this->currentTile = tileRight;
    }

    Tile* getTile() {
        return currentTile;
    }

    void move(Direction direction) {

        switch(direction) {

            case Direction::DIR_TOP:
                currentTile = tileTop;
                break;

            case Direction::DIR_BOT:
                currentTile = tileBot;
                break;

            case Direction::DIR_LEFT:
                currentTile = tileLeft;
                break;

            case Direction::DIR_RIGHT:
                currentTile = tileRight;
                break;
        }
    }

private:
    Tile* tileTop;
    Tile* tileBot;
    Tile* tileLeft;
    Tile* tileRight;
    Tile* currentTile;
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
                        pacman = new Pacman(column * 32, row *32, &tilePlayerLookingTop, &tilePlayerLookingBot, &tilePlayerLookingLeft, &tilePlayerLookingRight);
                        entity = pacman;
                    }
                    else {
                        entity = new Background(column * 32, row *32, &tileNormalBackground);
                        ERROR("PANIC, second player detected!!! OMG :O")
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

    while (running) {

        // render entities
        //window.renderEntity(pacman);

        renderMap(window, levelMap);

        // input
        while (inputHandler.pollEvent()) {

            if (inputHandler.isKeyPressed(SDLK_w)) {
                pacman->move(Direction::DIR_TOP);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                pacman->move(Direction::DIR_BOT);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                pacman->move(Direction::DIR_LEFT);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                pacman->move(Direction::DIR_RIGHT);
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }
        // update

        window.update();
        timer.sleep(8);
        timer.update();
    }

    return 0;
}
