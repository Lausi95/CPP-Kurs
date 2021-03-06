#ifndef HALLOWELT_WINDOW_H
#define HALLOWELT_WINDOW_H

#include <stdafx.h>
#include <Entity.h>

using entity_ptr = std::shared_ptr<Entity>;

// Wrapps a SDL_Window and gives it the ability to renderEntity Entities on its surface.
class Window {
public:
    // creates a new Window with a title and a width and a height.
    Window(const char *title, int width, int height);

    ~Window();

    // renders a entity on the surface of the window.
    void renderEntity(entity_ptr entity);

    //renders text on the surface of the windows
    void renderText(std::string);

    // updates the window to display the rendered surface.
    void update();

private:
    int width;
    int height;

    SDL_Window  *sdlWindow;
    SDL_Surface *sdlSurface;
};


#endif
