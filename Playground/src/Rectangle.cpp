#include <Rectangle.h>

Rectangle::Rectangle() {
    _x = _y = _width = _height = 0.0f;
}

Rectangle::Rectangle(float width, float height) {
    _x = _y = 0;
    _width = width;
    _height = height;
}

Rectangle::Rectangle(float x, float y, float width, float height) {
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}

float Rectangle::getX() {
    return _x;
}

float Rectangle::getY() {
    return _y;
}

float Rectangle::getWidth() {
    return _width;
}

float Rectangle::getHeight() {
    return _height;
}

void Rectangle::setX(float x) {
    _x = x;
}

void Rectangle::setY(float y) {
    _y = y;
}

void Rectangle::setWidth(float width) {
    _width = width;
}

void Rectangle::setHeight(float height) {
    _height = height;
}

void Rectangle::setPosition(float x, float y) {
    setX(x);
    setY(y);
}

void Rectangle::setDimension(float width, float height) {
    setWidth(width);
    setHeight(height);
}

bool Rectangle::intersects(Rectangle &rectangle) {
    bool l = rectangle._x > _x && rectangle._x < _x + _width;
    bool r = _x > rectangle._x && _x < rectangle._x + rectangle._width;
    bool t = rectangle._y > _y && rectangle._y < _y + _height;
    bool b = _y > rectangle._y && _y < rectangle._y + rectangle._height;
    return l || r || t || b;
}

SDL_Rect Rectangle::toSDLRect() {
    SDL_Rect rect;
    rect.x = (int) _x;
    rect.y = (int) _y;
    rect.w = (int) _width;
    rect.h = (int) _height;
    return rect;
}
