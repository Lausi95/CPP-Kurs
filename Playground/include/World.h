#ifndef PLAYGROUND_WORLD_H
#define PLAYGROUND_WORLD_H

#include <Camera.h>

class World {
    Camera* _camera;
    Entity* _entities;
    int _entityCount;

public:
    World(Camera* camera, Entity* entities, int entityCount);
    void draw();
};

#endif //PLAYGROUND_WORLD_H
