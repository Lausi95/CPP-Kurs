#include "stdafx.h"

class TestEntity : public Entity {

public:
    TestEntity(float x, float y, Tile* tile) : Entity(x, y) {
        this->tile = tile;
    }

    Tile* getTile() {
        return tile;
    }

private:
    Tile* tile;
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

    TestEntity testEntity(64, 64, &tilePoint);

    InputHandler inputHandler;
    bool running = true;
    Timer timer;

    while (running) {

        // render entities
        window.renderEntity(&testEntity);

        // input
        while (inputHandler.pollEvent()) {

            if (inputHandler.isKeyPressed(SDLK_w)) {

            }
            if (inputHandler.isKeyPressed(SDLK_s)) {

            }
            if (inputHandler.isKeyPressed(SDLK_a)) {

            }
            if (inputHandler.isKeyPressed(SDLK_d)) {

            }
            if (inputHandler.isKeyPressed(SDLK_SPACE)) {

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
