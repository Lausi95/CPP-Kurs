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

    std::vector<Button*> _buttons;
    Button* _highlightedButton;

    //needs to be unsigned to see if we have got back to last button if < 0
    long _hoveredButtonIndex;

private:
    int _updateCalls = 0;
    const int UPDATE_CALLS_THRESHOLD = 20;

    int _resetCount;
    const int RESET_UPDATE_CALLS_THRESHOLD = (int) 1.5 * UPDATE_CALLS_THRESHOLD;

public:
    Menu(Camera* camera,
         std::vector<Entity*>& entities,
         std::vector<Button*>& buttons,
         Input* input,
         SoundSystem* soundSystem)
            : World(camera, entities) {

        _background = entities.front();
        _input = input;

        _buttons = buttons;
        _highlightedButton = buttons.front();
        _hoveredButtonIndex = 0;

        updateHoveredButton();
    }

    void initialize() override {
        lockOn(_background);
    }

    void update(float dt) override {

        _resetCount++;
        if(_resetCount >= RESET_UPDATE_CALLS_THRESHOLD) {
            _updateCalls = 0;
            _resetCount = 0;
        }

        Button* currentButton = _buttons.at(_hoveredButtonIndex);

        if (_input->isSpaceDown()) {

            if (buttonUpdate())  {
                currentButton->_onclick();
                return;
            }
        }

        if (_input->isWDown()) {

            if (buttonUpdate())  {

                _buttons.at(_hoveredButtonIndex)->setHovered(false);

                _hoveredButtonIndex -= 1;
                if (_hoveredButtonIndex < 0) {
                    _hoveredButtonIndex = _buttons.size() - 1;
                }

                updateHoveredButton();
            }
        }

        if (_input->isSDown()) {

            if (buttonUpdate())  {

                _buttons.at(_hoveredButtonIndex)->setHovered(false);

                _hoveredButtonIndex += 1;
                if (_hoveredButtonIndex > _buttons.size() - 1) {
                    _hoveredButtonIndex = 0;
                }

                updateHoveredButton();
            }
        }

    }

    void updateHoveredButton() {
        _highlightedButton = _buttons.at(_hoveredButtonIndex);
        _highlightedButton->setHovered(true);
    }

    bool buttonUpdate() {
        //block inputs for a certain amount of update calls
        _updateCalls++;
        if (_updateCalls < UPDATE_CALLS_THRESHOLD) {
            return false;
        }

        _updateCalls = 0;
        return true;
    }
};


class MenuFactory {

public:
    Menu getMenu(Camera* camera,
                 Input* input,
                 SoundSystem* soundSystem,
                 std::vector<Button*> buttons);
};



#endif //PLAYGROUND_MENUFACTORY_H
