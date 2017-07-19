#include <BurnEngine.h>
#include <Level.h>
#include <Player.h>

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

    Texture playerLookingLeftTexture("assets/images/tiles/player_boy_left.png", 32, 32);
    Texture playerLookingRightTexture("assets/images/tiles/player_boy_right.png", 32, 32);
    Tile playerLookingLeftTile(playerLookingLeftTexture, 0, 0);
    Tile playerLookingRightTile(playerLookingRightTexture, 0, 0);
    std::array<Tile*, 2> playerTiles {
            &playerLookingLeftTile,
            &playerLookingRightTile
    };

    burnengine::Player player(playerTiles, 200, 200);

    Game game("Burning Kiddies", level.getWidth(), level.getHeight());

    while (game.isRunning()) {
        game.update();
        level.render(game);
        game.render(player);

        if (game.isKeyDown(SDLK_d)) {
            player.setX(player.getX() + 0.3f);
        }
        if (game.isKeyDown(SDLK_a)) {
            player.setX(player.getX() - 0.3f);
        }
    }

    return 0;
}