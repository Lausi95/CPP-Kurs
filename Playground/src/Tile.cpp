#include <Tile.h>

Tile::Tile(Texture *texture, int x, int y, int width, int height) {
    _texture = texture;
    _rectangle = new Rectangle(x, y, width, height);
}

Tile::~Tile() {
    delete _rectangle;
}

int Tile::getWidth() {
    return _rectangle->getWidth();
}

int Tile::getHeight() {
    return _rectangle->getHeight();
}

Texture *Tile::getTexture() {
    return _texture;
}

Rectangle *Tile::getRectangle() {
    return _rectangle;
}
