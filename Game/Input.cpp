#include "Input.h"


bool InputHandler::pollEvent() {
    return SDL_PollEvent(&event);
}

bool InputHandler::isKeyDown(SDL_Keycode keyCode) {
    return event.type == SDL_KEYDOWN && event.key.keysym.sym == keyCode;
}

bool InputHandler::isKeyUp(SDL_Keycode keyCode) {
    return event.type == SDL_KEYUP && event.key.keysym.sym == keyCode;
}

bool InputHandler::isQuitEvent() {
    return event.type == SDL_QUIT;
}

bool InputHandler::isKeyPressed(SDL_Keycode keyCode) {
    return event.key.state == SDL_PRESSED && event.key.keysym.sym == keyCode;
}

