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

    // game loop
    bool running = true;
    SDL_Event event;

    while (running) {
        for (int i = 0; i < 100; i++) {
            window.render(background[i]);
        }

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        window.update();
        SDL_Delay(16);
    }

    // clean up resources
    for (int i = 0; i < 100; i++) {
        delete background[i];
    }

    return 0;
}