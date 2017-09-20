#ifndef PLAYGROUND_RECTANGLE_H
#define PLAYGROUND_RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle {
    float _x;
    float _y;
    float _width;
    float _height;

public:
    Rectangle();
    Rectangle(float width, float height);
    Rectangle(float x, float y, float width, float height);

    float getX();
    float getY();
    float getWidth();
    float getHeight();

    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);

    void setPosition(float x, float y);
    void setDimension(float width, float height);

    bool intersects(Rectangle& rectangle);

    SDL_Rect toSDLRect();
};

#endif //PLAYGROUND_RECTANGLE_H
