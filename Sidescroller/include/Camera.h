#ifndef PLAYGROUND_CAMERA_H
#define PLAYGROUND_CAMERA_H

#include <Entity.h>
#include <SDL2/SDL.h>

class Camera {
    SDL_Surface* _surface;
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    int _width;
    int _height;
    int _offsetX;
    int _offsetY;

public:
    Camera(int width, int height, const char* title);

    void setOffsetX(int offset);
    void setOffsetY(int offset);
    void setOffset(int offsetX, int offsetY);
    void lockOn(Entity* entity);

    void clear();
    void show(Entity* entity);
    void update();
};

#endif //PLAYGROUND_CAMERA_H
