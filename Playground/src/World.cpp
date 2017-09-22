#include <World.h>

World::World(Camera *camera, std::vector<Entity*> entities) {
    _camera = camera;
    _entities = entities;
}

void World::draw() {
    _camera->clear();
    for (Entity* entity : _entities)
        _camera->show(entity);
    _camera->update();
}

void World::lockOn(Entity* entity) {
    _camera->lockOn(entity);
}

bool World::initialized() {
    return _initialized;
}

void World::setInitialized(bool initialized) {
    _initialized = initialized;
}
