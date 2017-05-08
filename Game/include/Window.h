//
// Created by tom on 05.05.17.
//

#ifndef HALLOWELT_WINDOW_H
#define HALLOWELT_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"

class Window {
public:
    Window(const char *title, int width, int height);

    void render(Entity* entity);
    void update();

    int getWidth();
    int getHeight();

private:
    const char* title;
    int width;
    int height;

    SDL_Window  *sdlWindow;
    SDL_Surface *sdlSurface;
};


#endif //HALLOWELT_WINDOW_H
