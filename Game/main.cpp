#include <time.h>

#include "logging.h"

#include "Texture.h"
#include "Tile.h"
#include "Entity.h"
#include "Window.h"
#include "Input.h"

class SimpleEntity : public Entity {
private:
    Tile* tile;

public:
    SimpleEntity(int x, int y, Tile* tile) : Entity(x, y) {
        this->tile = tile;
    }

    Tile* getTile() {
        return this->tile;
    }
};

int main(int argc, char** argv) {
    Window window("Title", 32 * 10, 32 * 10);

    // initializing
    Texture texture("assets/tiles.png");
    Tile wallTile(&texture, 0, 0, 32, 32);
    Tile floorTile(&texture, 0, 32, 32, 32);
    Tile ghostTile(&texture, 5 * 32, 0, 32, 32);

    Entity* background[100]; // space for 10 tiles horizontal and vertical -> 100 tiles total
    for (int i = 0; i < 100; i++) {
        int x = i % 10;
        int y = i / 10;

        // entities at to borders are walls
        if (x == 0 || y == 0 || x == 9 || y == 9) {
            background[i] = new SimpleEntity(x * 32, y * 32, &wallTile);
        }
        else {
            background[i] = new SimpleEntity(x * 32, y * 32, &floorTile);
        }
    }

    SimpleEntity ghost(32 * 5, 32 * 5, &ghostTile);

    // game loop
    bool running = true;
    InputHandler inputHandler;

    struct timespec c1;
    clock_gettime(CLOCK_MONOTONIC, &c1);

    while (running) {
        // render
        for (int i = 0; i < 100; i++) {
            window.render(background[i]);
        }
        window.render(&ghost);

        // input based update
        while (inputHandler.pollEvent()) {
            if (inputHandler.isKeyDown(SDLK_w) && ghost.getY() > 32) {
                DEBUG("move up")
                ghost.setY(ghost.getY() - 32);
            }

            if (inputHandler.isKeyDown(SDLK_a) && ghost.getX() > 32) {
                DEBUG("move left")
                ghost.setX(ghost.getX() - 32);
            }

            if (inputHandler.isKeyDown(SDLK_s) && ghost.getY() < 8 * 32) {
                DEBUG("move down")
                ghost.setY(ghost.getY() + 32);
            }

            if (inputHandler.isKeyDown(SDLK_d) && ghost.getX() < 8 * 32) {
                DEBUG("move right")
                ghost.setX(ghost.getX() + 32);
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }

        // get the time since last frame (tslf)
        struct timespec c2;
        clock_gettime(CLOCK_MONOTONIC, &c2);
        struct timespec diff;
        diff.tv_nsec = c2.tv_nsec - c1.tv_nsec;
        diff.tv_sec = c2.tv_sec - c1.tv_sec;
        float tslf = (float)diff.tv_sec + (float)diff.tv_nsec / 1000000000.0f;
        c1 = c2;

        // time based update (none yet)
        ghost.setY(ghost.getY() + 5.0f * tslf);

        window.update();
        SDL_Delay(16);
    }

    // clean up resources
    INFO("cleaning up resources")
    for (int i = 0; i < 100; i++) {
        delete background[i];
    }

    return 0;
}
