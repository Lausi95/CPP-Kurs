#include <BurnEngine.h>
#include <Level.h>

int main() {
    using namespace burnengine;

    initialize();
    Texture texture("assets/images/tiles/background_tile_slab.png", 32, 32);
    Tile tile(texture, 0, 0);
    BackgroundEntity backgroundEntity(tile);

    Level level(backgroundEntity, 800, 608);

    Game game("Burning Kiddies", level.getWidth(), level.getHeight());

    while (game.isRunning()) {
        game.update();
        level.render(game);
    }

    return 0;
}