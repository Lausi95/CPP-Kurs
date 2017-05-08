#include "include/logging.h"

#include "include/Texture.h"
#include "include/Tile.h"
#include "include/Entity.h"
#include "include/Window.h"

#include <list>

using namespace std;


class Wall : public Entity {
private:
    Tile* tile;

public:
    Wall(int x, int y, Tile* tile) : Entity(x, y) {
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

    Entity* entities[100];
    for (int i = 0; i < 100; i++) {
        int x = i / 10;
        int y = i % 10;
        if (x == 0 || y == 0 || x == 9 || y == 9) {
            entities[i] = new Wall(x * 32, y * 32, &wallTile);
        }
        else {
            entities[i] = new Wall(x * 32, y * 32, &floorTile);
        }
    }


    // game loop
    for (int i = 0; i < 100; i++) {
        window.render(entities[i]);
    }
    window.update();
    SDL_Delay(5000);

    // clean up resources
    for (int i = 0; i < 100; i++) {
        delete entities[i];
    }

    return 0;
}