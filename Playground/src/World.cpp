#include <World.h>

World::World(Camera *camera, Entity* entities, int entityCount) {
    _camera = camera;
    _entities = entities;
    _entityCount = entityCount;
}

void World::draw() {
    _camera->clear();
    for (int i = 0; i < _entityCount; i++)
        _camera->show(&_entities[i]);
    _camera->update();
}
