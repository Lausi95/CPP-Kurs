#include <Entity.h>

Entity::Entity() {
    _rectangle = new Rectangle();
}

Entity::Entity(float x, float y, int width, int height) {
    _rectangle = new Rectangle(x, y, width, height);
}

Entity::~Entity() {
    delete _rectangle;
}

int Entity::getWidth() {
    return _rectangle->getWidth();
}

int Entity::getHeight() {
    return _rectangle->getHeight();
}

float Entity::getX() {
    return _rectangle->getX();
}

float Entity::getY() {
    return _rectangle->getY();
}

void Entity::setX(float x) {
    _rectangle->setX(x);
}

void Entity::setY(float y) {
    _rectangle->setY(y);
}

Rectangle *Entity::getRectangle() {
    return _rectangle;
}

int Entity::getBottom() {
    return (int) _rectangle->getY() + _rectangle->getHeight();
}
