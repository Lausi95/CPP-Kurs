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

float Entity::getBottom() {
    return _rectangle->getY() + _rectangle->getHeight();
}

void Entity::setBottom(float bottom) {
    _rectangle->setY(bottom - (float)_rectangle->getHeight());
}

float Entity::getTop() {
    return _rectangle->getY();
}

void Entity::setTop(float top) {
    _rectangle->setY(top);
}

float Entity::getLeft() {
    return _rectangle->getX();
}

void Entity::setLeft(float left) {
    _rectangle->setX(left);
}

float Entity::getRight() {
    return _rectangle->getX() + _rectangle->getWidth();
}

void Entity::setRight(float right) {
    _rectangle->setX(right - (float) _rectangle->getWidth());
}
