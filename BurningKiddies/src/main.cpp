#include <BurnEngine.h>
#include <Level.h>

int main() {
    using namespace burnengine;

    initialize();

    Texture texture("assets/images/tiles/background_tile_slab.png", 32, 32);
    Tile tile(texture, 0, 0);
    BackgroundEntity backgroundEntity(tile);

    Texture lavaTextue("assets/images/tiles/floor_lava.png", 32, 32);
    Tile lavaTile(lavaTextue, 0, 0);
    LavaEntity lavaEntity(lavaTile);

    Level level(800, 608);
    level.setBackground(backgroundEntity);
    level.setLavaEntity(lavaEntity);

    Game game("Burning Kiddies", level.getWidth(), level.getHeight());

    while (game.isRunning()) {
        game.update();
        level.render(game);
    }

    return 0;
}