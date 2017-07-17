#include <Level.h>

namespace burnengine {

    BackgroundEntity::BackgroundEntity(Tile& tile) : Entity(0, 0) {
        this->tile = &tile;
    }

    Tile *burnengine::BackgroundEntity::getTile() {
        return tile;
    }

    Level::Level(burnengine::BackgroundEntity &backgroundEntity, int width, int height) {
        this->backgroundEntity = &backgroundEntity;
        this->width = width;
        this->height = height;
    }

    void Level::render(burnengine::Game &game) {
        renderBackground(game);
    }

    void Level::renderBackground(burnengine::Game& game) const {
        int nx = this->width / this->backgroundEntity->getWidth();
        int ny = this->height / this->backgroundEntity->getHeight();
        for (int x = 0; x < nx; x++) {
            for (int y = 0; y < ny; y++) {
                this->backgroundEntity->setX(x * this->backgroundEntity->getWidth());
                this->backgroundEntity->setY(y * this->backgroundEntity->getHeight());
                game.render(*this->backgroundEntity);
            }
        }
    }

}
