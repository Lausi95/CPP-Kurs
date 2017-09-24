#include <Input.h>

void updateKeyStatus(SDL_Event &event, SDL_Keycode keyCode, bool &b) {
    if (event.key.keysym.sym == keyCode) {
        if (event.type == SDL_KEYDOWN) b = true;
        if (event.type == SDL_KEYUP)   b = false;
    }
}

bool getKeyAndUpdate(bool& b, bool reset) {
    bool isDown = b;
    if (reset && isDown) b = false;
    return isDown;
}

Input::Input() {
    _quitTriggered = false;
}

bool Input::quitTriggered() {
    return _quitTriggered;
}

void Input::update() {
    while (SDL_PollEvent(&_event)) {
        handleQuitEvent();
        updateKeyStatus(_event, SDLK_s, _sIsDown);
        updateKeyStatus(_event, SDLK_w, _wIsDown);
        updateKeyStatus(_event, SDLK_a, _aIsDown);
        updateKeyStatus(_event, SDLK_d, _dIsDown);
        updateKeyStatus(_event, SDLK_SPACE, _spaceIsDown);
    }
}

void Input::handleQuitEvent() {
    if (_event.type == SDL_QUIT)
        _quitTriggered = true;
}

bool Input::isADown() {
    return _aIsDown;
}

bool Input::isDDown() {
    return _dIsDown;
}

bool Input::isWDown() {
    return _wIsDown;
}

bool Input::isSDown() {
    return _sIsDown;
}

bool Input::isSpaceDown() {
    return _spaceIsDown;
}

bool Input::isADown(bool reset) {
    return getKeyAndUpdate(_aIsDown, reset);
}

bool Input::isDDown(bool reset) {
    return getKeyAndUpdate(_dIsDown, reset);
}

bool Input::isWDown(bool reset) {
    return getKeyAndUpdate(_wIsDown, reset);
}

bool Input::isSDown(bool reset) {
    return getKeyAndUpdate(_sIsDown, reset);
}

bool Input::isSpaceDown(bool reset) {
    return getKeyAndUpdate(_spaceIsDown, reset);
}
