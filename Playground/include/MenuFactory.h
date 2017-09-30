//
// Created by hendrik on 29.09.17.
//

#ifndef PLAYGROUND_MENUFACTORY_H
#define PLAYGROUND_MENUFACTORY_H

#include <World.h>
#include <Input.h>
#include <state/Worlds.h>
#include <SoundSystem.h>
#include <entities/Button.h>

const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 50;
const int BUTTON_COUNT = 3;
const int VERTICAL_MARGIN = 100;

class Menu : public World {

    Entity* _background;
    Input*  _input;
    void (*_callbackChangeWorld)(Worlds);

    std::vector<Button*> _buttons;
    Button* _highlightedButton;
    long _highlightedButtonIndex;

public:
    Menu(Camera* camera,
         std::vector<Entity*>& entities,
         std::vector<Button*>& buttons,
         Input* input,
         SoundSystem* soundSystem,
         void (*callbackChangeWorld)(Worlds))
            : World(camera, entities) {

        _background = entities.front();
        _input = input;
        _callbackChangeWorld = callbackChangeWorld;

        _buttons = buttons;
        _highlightedButton = buttons.front();
        _highlightedButtonIndex = 0;
    }

    void initialize() override {

    }

    void update(float dt) override {
        lockOn(_background);

        if (_input->isSpaceDown()) {

            _buttons.at(_highlightedButtonIndex);
            //_callbackChangeWorld(WORLD_LEVEL_1);
        }

        if (_input->isWDown()) {

            _highlightedButtonIndex -= 1;
            if (_highlightedButtonIndex < 0) {
                _highlightedButtonIndex = _buttons.size() - 1;
            }

        }

        if (_input->isSDown()) {

            _highlightedButtonIndex += 1;
            if (_highlightedButtonIndex > _buttons.size() - 1) {
                _highlightedButtonIndex = 0;
            }
        }

        _highlightedButton = _buttons.at(_highlightedButtonIndex);
        _highlightedButton->setHovered(true);
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
