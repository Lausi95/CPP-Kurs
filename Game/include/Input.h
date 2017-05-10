#ifndef SDL_GAME_INPUT_H
#define SDL_GAME_INPUT_H

#include <SDL2/SDL.h>

class InputHandler {
public:
    bool pollEvent();

    bool isKeyDown(SDL_Keycode keyCode);
    bool isKeyUp(SDL_Keycode keyCode);
    bool isQuitEvent();
private:
    SDL_Event event;
};

#endif
