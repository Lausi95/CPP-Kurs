#ifndef SDL_GAME_INPUT_H
#define SDL_GAME_INPUT_H

#include <SDL2/SDL.h>

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

class InputHandler {
public:
    bool pollEvent();

    bool isKeyDown(SDL_Keycode keyCode);
    bool isKeyUp(SDL_Keycode keyCode);
    bool isKeyPressed(SDL_Keycode keyCode);
    bool isMouseDown();

    int getMouseX();
    int getMouseY();

    bool isQuitEvent();
private:
    SDL_Event event;
};

#endif
