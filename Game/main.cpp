#include "include/logging.h"

#include "include/Texture.h"
#include "include/Tile.h"
#include "include/Entity.h"
#include "include/Window.h"

using namespace std;


class Wall : public Entity {
public:
    Wall(int x, int y, int width, int height, Tile* tile) : Entity(x, y, width, height) {
        this->tile = tile;
    }

    Tile* getTile();

private:
    Tile* tile;
};

Tile *Wall::getTile() {
    return this->tile;
}


int main(int argc, char** argv) {
    Window window("Title", 400, 300);
    window.initialize();

    Texture texture("assets/tiles.png");
    Tile tile(&texture, 0, 0, 32, 32);

    Wall wallEntity(0, 0, 32, 32, &tile);

    // "gameloop"
    window.render(&wallEntity);
    window.update();
    SDL_Delay(2000);

    return 0;
}