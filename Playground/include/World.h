#ifndef PLAYGROUND_WORLD_H
#define PLAYGROUND_WORLD_H

#include <Camera.h>
#include <vector>

class World {
    Camera* _camera;
    std::vector<Entity*> _entities;
    int _entityCount;

public:
    World(Camera* camera, std::vector<Entity*> entities, int entityCount);
    void draw();
};

#endif //PLAYGROUND_WORLD_H
