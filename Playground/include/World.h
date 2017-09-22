#ifndef PLAYGROUND_WORLD_H
#define PLAYGROUND_WORLD_H

#include <Camera.h>
#include <vector>

class World {
    Camera* _camera;
    std::vector<Entity*> _entities;

public:
    World(Camera* camera, std::vector<Entity*> entities);
    void draw();
    void lockOn(Entity* entity);

    virtual void update(float dt) = 0;
};

#endif //PLAYGROUND_WORLD_H
