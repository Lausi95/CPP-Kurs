#ifndef PLAYGROUND_INPUT_H
#define PLAYGROUND_INPUT_H

#include <SDL2/SDL.h>

class Input {
    SDL_Event _event;

    bool _quitTriggered;
    bool _aIsDown;
    bool _dIsDown;
    bool _wIsDown;
    bool _sIsDown;
    bool _spaceIsDown;

    void handleQuitEvent();

public:
    Input();

    bool isADown();
    bool isDDown();
    bool isWDown();
    bool isSDown();
    bool isSpaceDown();

    bool isADown(bool reset);
    bool isDDown(bool reset);
    bool isWDown(bool reset);
    bool isSDown(bool reset);
    bool isSpaceDown(bool reset);

    void update();
    bool quitTriggered();
};

#endif //PLAYGROUND_INPUT_H
