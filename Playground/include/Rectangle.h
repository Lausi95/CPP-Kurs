#ifndef PLAYGROUND_RECTANGLE_H
#define PLAYGROUND_RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle {
    float _x;
    float _y;
    int _width;
    int _height;

public:
    Rectangle();
    Rectangle(int width, int height);
    Rectangle(float x, float y, int width, int height);

    float getX();
    float getY();
    int getWidth();
    int getHeight();

    void setX(float x);
    void setY(float y);
    void setWidth(int width);
    void setHeight(int height);

    void setPosition(float x, float y);
    void setDimension(int width, int height);

    bool intersects(Rectangle& rectangle);

    SDL_Rect toSDLRect();
};

#endif //PLAYGROUND_RECTANGLE_H
