#include "logging.h"

#include "Texture.h"
#include "Tile.h"
#include "Entity.h"
#include "Window.h"

using namespace std;


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

    Entity* background[100];
    for (int i = 0; i < 100; i++) {
        int x = i / 10;
        int y = i % 10;
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
    SDL_Event event;

    while (running) {
        // render
        for (int i = 0; i < 100; i++) {
            window.render(background[i]);
        }
        window.render(&ghost);

        // update
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        DEBUG("move up")
                        if (ghost.getY() > 32) ghost.setY(ghost.getY() - 32);
                        break;
                    case SDLK_a:
                        DEBUG("move left")
                        if (ghost.getX() > 32) ghost.setX(ghost.getX() - 32);
                        break;
                    case SDLK_s:
                        DEBUG("move down")
                        if (ghost.getY() < 8 * 32) ghost.setY(ghost.getY() + 32);
                        break;
                    case SDLK_d:
                        DEBUG("move right")
                        if (ghost.getX() < 8 * 32) ghost.setX(ghost.getX() + 32);
                        break;
                    default:break;
                }
            }

            if (event.type == SDL_QUIT) {
                INFO("Quit event triggered")
                running = false;
            }
        }

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