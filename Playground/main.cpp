#include <World.h>
#include <Input.h>
#include <entities/SimpleEntity.h>
#include <entities/Player.h>

Camera camera(800, 1000, "You May Not Touch The Ground");

Texture texture("assets/rooms/gate.png");
Tile tile(&texture, 0, 0, 1000, 700);
SimpleEntity entity(&tile, 0, 0);

Texture textureEgg("assets/items/dragonegg.png");
Tile tileEgg(&textureEgg, 0, 0, 118, 135);
std::array<Tile*, 2> playerTiles {&tileEgg, &tileEgg};
Player player(playerTiles, 0, 0, 118, 135);

std::vector<Entity*> e {&entity, &player};
World world(&camera, e, 2);

Input input;

int main() {
    do {
        input.update();
        if (input.isADown())
            player.setVx(-1.0f);
        else if (input.isDDown())
            player.setVx(1.0f);
        else
            player.setVx(0.0f);

        if (input.isWDown() && player.canJump())
            player.jump();

        player.update();

        if (player.getBottom() >= entity.getBottom()) {
            player.setVy(0);
            player.enableJump();
        } else {
            player.addVy(0.2f);
        }

        camera.lockOn(&player);
        world.draw();
    } while (!input.quitTriggered());
}
