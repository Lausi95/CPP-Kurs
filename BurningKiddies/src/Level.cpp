#include <Level.h>

namespace burnengine {

    BackgroundEntity::BackgroundEntity(Tile& tile) : Entity(0, 0) {
        this->tile = &tile;
    }

    Tile *burnengine::BackgroundEntity::getTile() {
        return tile;
    }

    Level::Level(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Level::render(burnengine::Game &game) {
        if (backgroundEntity != nullptr)
            renderBackground(game);

        if (lavaEntity != nullptr) {
            int nx = getWidth() / lavaEntity->getWidth();
            for (int x = 0; x < nx; ++x) {
                lavaEntity->setX(x * lavaEntity->getWidth());
                lavaEntity->setY(getHeight() - lavaEntity->getHeight() + 1);
                game.render(*lavaEntity);
            }
        }

        for (burnengine::Entity* entity : environment)
            game.render(*entity);
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

    void Level::setBackground(BackgroundEntity& entity) {
        this->backgroundEntity = &entity;
    }

    void Level::addEnvironmentEntity(Entity &entity) {
        this->environment.push_back(&entity);
    }

    void Level::setLavaEntity(LavaEntity& lavaEntity) {
        this->lavaEntity = &lavaEntity;
    }

    LavaEntity::LavaEntity(Tile& lavaTile) : Entity(0, 0) {
        this->tile = &lavaTile;
    }

    Tile* LavaEntity::getTile() {
        return tile;
    }

}
