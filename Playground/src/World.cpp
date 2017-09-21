#include <World.h>

World::World(Camera *camera, std::vector<Entity*> entities, int entityCount) {
    _camera = camera;
    _entities = entities;
    _entityCount = entityCount;
}

void World::draw() {
    _camera->clear();
    for (Entity* entity : _entities)
        _camera->show(entity);
    _camera->update();
}
