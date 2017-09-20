#include <Entity.h>

Entity::Entity(Tile *tile) {
    _tile = tile;
    _rectangle = new Rectangle();
}

Entity::Entity(Tile *tile, float x, float y) {
    _tile = tile;
    _rectangle = new Rectangle(x, y, tile->getWidth(), tile->getHeight());
}

Entity::Entity(Texture *texture, int width, int height, float x, float y) {
    _tile = new Tile(texture, 0, 0, width, height);
    _rectangle = new Rectangle(x, y, width, height);
    _tileIsSelfCreated = true;
}

Entity::~Entity() {
    delete _rectangle;
    if (_tileIsSelfCreated)
        delete _tile;
}

float Entity::getWidth() {
    return _rectangle->getWidth();
}

float Entity::getHeight() {
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

Tile *Entity::getTile() {
    return _tile;
}

Rectangle *Entity::getRectangle() {
    return _rectangle;
}
