#include <BurnEngine.h>
#include <Level.h>

int main() {
    using namespace burnengine;

    initialize();
    Level level(800, 608);

    Texture backgroundTexture("assets/images/tiles/background_tile_slab.png", 32, 32);
    Tile backgroundTile(backgroundTexture, 0, 0);
    BackgroundEntity backgroundEntity(backgroundTile);
    level.setBackground(backgroundEntity);

    Texture lavaTexture("assets/images/tiles/floor_lava.png", 32, 32);
    Tile lavaTile(lavaTexture, 0, 0);
    LavaEntity lavaEntity(lavaTile);
    level.setLavaEntity(lavaEntity);

    Game game("Burning Kiddies", level.getWidth(), level.getHeight());

    while (game.isRunning()) {
        game.update();
        level.render(game);
    }

    return 0;
}