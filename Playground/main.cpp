#include <World.h>
#include <Input.h>

Camera camera(400, 300, "You May Not Touch The Ground");

Texture texture("assets/rooms/gate.png");
Entity entity(&texture, 1000, 700, 0, 0);

Texture textureEgg("assets/items/dragonegg.png");
Entity egg(&textureEgg, 118, 135, 0, 0);

Entity entities[] = {entity, egg};
World world(&camera, entities, 2);

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
