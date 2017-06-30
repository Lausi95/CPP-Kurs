#include "stdafx.h"

enum Direction {
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

            case DIR_TOP:
                currentTile = tileTop;
                break;

            case DIR_BOT:
                currentTile = tileBot;
                break;

            case DIR_LEFT:
                currentTile = tileLeft;
                break;

            case DIR_RIGHT:
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

int main(int argc, char** argv) {

    srand (time(NULL));

    int levelWidth = 800;
    int levelHeigth = 600;

    Window window("Punktefresser", levelWidth, levelHeigth);

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

    Pacman pacman(400, 300, &tilePlayerLookingTop, &tilePlayerLookingBot, &tilePlayerLookingLeft, &tilePlayerLookingRight);

    InputHandler inputHandler;
    bool running = true;
    Timer timer;

    while (running) {

        // render entities
        window.renderEntity(&pacman);

        // input
        while (inputHandler.pollEvent()) {

            if (inputHandler.isKeyPressed(SDLK_w)) {
                pacman.move(DIR_TOP);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                pacman.move(DIR_BOT);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                pacman.move(DIR_LEFT);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                pacman.move(DIR_RIGHT);
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
