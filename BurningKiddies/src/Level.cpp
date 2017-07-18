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

    void Level::render(burnengine::Game &game) const {
        if (backgroundEntity != nullptr)
            renderBackground(game);

        if (lavaEntity != nullptr)
            renderLava(game);

        for (burnengine::Entity* entity : environment)
            game.render(*entity);
    }

    // precondition: the lavaEntity is not null
    void Level::renderLava(Game& game) const {
        int nx = getWidth() / lavaEntity->getWidth();
        for (int x = 0; x < nx; x++)
            renderLavaChunk(game, x);
    }

    // precondition: the lavaEntity is not null
    void Level::renderLavaChunk(Game& game, int x) const {
        lavaEntity->setX(x * lavaEntity->getWidth());
        lavaEntity->setY(getHeight() - lavaEntity->getHeight() + 1);
        game.render(*lavaEntity);
    }

    // precondition: the backgroundEntity is not null
    void Level::renderBackground(burnengine::Game& game) const {
        int nx = this->width / this->backgroundEntity->getWidth();
        int ny = this->height / this->backgroundEntity->getHeight();
        for (int x = 0; x < nx; x++)
            for (int y = 0; y < ny; y++)
                renderBackgroundChunk(game, x, y);
    }

    // precondition: the backgroundEntity is not null
    void Level::renderBackgroundChunk(Game& game, int x, int y) const {
        backgroundEntity->setX(x * backgroundEntity->getWidth());
        backgroundEntity->setY(y * backgroundEntity->getHeight());
        game.render(*backgroundEntity);
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
