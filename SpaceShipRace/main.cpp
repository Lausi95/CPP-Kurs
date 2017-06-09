#include "stdafx.h"

class Item : public Entity {
private:
    Tile* tile;

public:
    Item(Tile* tile, float x, float y);
    Tile* getTile();
};

Item::Item(Tile* tile, float x, float y) : Entity(x, y) {
    this->tile = tile;
}

Tile *Item::getTile() {
    return tile;
}

struct GameState {
    bool chestFound = false;
    bool talkedToMage = false;
};

int main(int argc, char** argv) {

    Window window("SpaceShipRace", 1024, 800);

    Texture texture_background("assets/background.png");
    Texture texture_spaceships("assets/spaceships.png");
    Texture texture_stars1("assets/stars1.png");
    Texture texture_stars2("assets/stars2.png");
    Texture texture_stars3("assets/stars3.png");

    Tile tile_background(&texture_background, 0, 0, 1024, 800);
    Tile tile_spaceship(&texture_spaceships, 0, 0, 1000, 700);
    Tile tile_stars1(&texture_stars1, 0, 0, 800, 600);
    Tile tile_stars2(&texture_stars2, 0, 0, 800, 600);
    Tile tile_stars3(&texture_stars3, 0, 0, 800, 600);

    srand(time(NULL));

    InputHandler inputHandler;
    bool running = true;
    Timer timer;
    GameState gameState;

    while (running) {
        // renderEntity
        //TODO:

        // input
        while (inputHandler.pollEvent()) {
            if (inputHandler.isKeyPressed(SDLK_w)) {
                //move space ship to top
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                //move space ship to bottom
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }
        // update

        window.update();
        timer.sleep(16);
        timer.update();
    }

    return 0;
}
