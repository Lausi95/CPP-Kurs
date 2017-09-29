//
// Created by hendrik on 29.09.17.
//

#ifndef PLAYGROUND_MENUFACTORY_H
#define PLAYGROUND_MENUFACTORY_H

#include <World.h>
#include <Input.h>
#include <state/Worlds.h>
#include <SoundSystem.h>

const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 50;

const int BUTTON_COUNT = 3;
const int VERTICAL_MARGIN = 100;

class Menu : public World {

    Entity* _background;
    Input*  _input;
    void (*_callbackChangeWorld)(Worlds);

public:
    Menu(Camera* camera,
         const std::vector<Entity*>& entities,
         Input* input,
         SoundSystem* soundSystem,
         void (*callbackChangeWorld)(Worlds))
            : World(camera, entities) {

        _background = entities.front();
        _input = input;
        _callbackChangeWorld = callbackChangeWorld;
    }

    void initialize() override {

    }

    void update(float dt) override {
        lockOn(_background);

        if (_input->isSpaceDown()) {
            _callbackChangeWorld(WORLD_LEVEL_1);
        }
    }
};


class MenuFactory {

public:
    Menu getMenu(Camera* camera,
                 Input* input,
                 SoundSystem* soundSystem,
                 void (*callbackChangeWorld)(Worlds));
};



#endif //PLAYGROUND_MENUFACTORY_H
