#include <BurnEngine.h>
#include <Level.h>
#include <Player.h>

#define GRAVITY 9.81f
#define VELOCITY_NORM 0.3f

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
        player.update();

        player.setAY(VELOCITY_NORM * VELOCITY_NORM);

        if (player.getY() > level.getHeight() - lavaEntity.getHeight() * 2) {
            player.setY(level.getHeight() - lavaEntity.getHeight() * 2);
            player.setVY(0);
            player.setAY(0);
        }

        if (game.isKeyDown(SDLK_d)) {
            player.setVX(1.7f);
            player.setLookingDirection(LookingDirection::Right);
        }
        if (game.isKeyDown(SDLK_a)) {
            player.setVX(-1.7f);
            player.setLookingDirection(LookingDirection::Left);
        }

        if (game.isKeyDown(SDLK_w) && player.getAY() == 0) {
            player.setVY(-7);
            player.setAY(GRAVITY * VELOCITY_NORM);
        }

        if (!game.isKeyDown(SDLK_d) && !game.isKeyDown(SDLK_a)) {
            player.setVX(0);
        }
    }

    return 0;
}