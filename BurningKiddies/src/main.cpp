#include <iostream>
#include <BurnEngine.h>

#include <SDL2/SDL.h>

class SimpleEntity : public burnengine::Entity {
    burnengine::Tile* tile;

public:
    SimpleEntity(burnengine::Tile& tile, int x, int y) : Entity(x, y) {
        this->tile = &tile;
    }

    burnengine::Tile* getTile() {
        return tile;
    }
};

int main() {
    using namespace burnengine;

    initialize();
    Game game("Burning Kiddies", 400, 300);

    Texture dirtTexture("assets/images/tiles/floor_dirt.jpg", 32, 32);
    Tile dirtTile(dirtTexture, 0, 0);
    SimpleEntity entity(dirtTile, 0, 0);

    while (game.isRunning()) {
        game.update();

        if (game.getTicks() % 1000 == 0) {
            if (game.isKeyDown(SDLK_w)) {
                entity.getRect()->y--;
            }

            if (game.isKeyDown(SDLK_a)) {
                entity.getRect()->x--;
            }

            if (game.isKeyDown(SDLK_s)) {
                entity.getRect()->y++;
            }

            if (game.isKeyDown(SDLK_d)) {
                entity.getRect()->x++;
            }
        }

        game.render(entity);
    }

    return 0;
}