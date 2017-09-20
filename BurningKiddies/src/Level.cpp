#include <Level.h>

namespace burnengine {

    BackgroundEntity::BackgroundEntity(Tile& tile) : Entity(0, 0) {
        this->tile = &tile;
    }

    Tile* burnengine::BackgroundEntity::getTile() {
        return tile;
    }

    Level::Level(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Level::setBackground(BackgroundEntity& entity) {
        this->backgroundEntity = &entity;
    }

    void Level::addEnvironmentEntity(Entity<int> &entity) {
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
