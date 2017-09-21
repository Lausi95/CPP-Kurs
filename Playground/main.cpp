#include <World.h>
#include <Input.h>
#include <vector>

class SimpleEntity : public Entity {
    Tile* _tile;

public:
    SimpleEntity(Tile* tile, float x, float y) : Entity(x, y, tile->getWidth(), tile->getHeight()) {
        _tile = tile;
    }

    Tile* getTile() {
        return _tile;
    }
};

Camera camera(400, 300, "You May Not Touch The Ground");

Texture texture("assets/rooms/gate.png");
Tile tile(&texture, 0, 0, 1000, 700);
SimpleEntity entity(&tile, 0, 0);

Texture textureEgg("assets/items/dragonegg.png");
Tile tileEgg(&textureEgg, 0, 0, 118, 135);
SimpleEntity egg(&tileEgg, 0, 0);

std::vector<Entity*> e {&entity, &egg};
World world(&camera, e, 2);

Input input;

int main() {
    do {
        input.update();
        if (input.isADown())
            egg.setX(egg.getX() - 1.0f);
        if (input.isDDown())
            egg.setX(egg.getX() + 1.0f);
        if (input.isWDown())
            egg.setY(egg.getY() - 1.0f);
        if (input.isSDown())
            egg.setY(egg.getY() + 1.0f);
        camera.lockOn(&egg);
        world.draw();
    } while (!input.quitTriggered());
}
