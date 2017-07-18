#ifndef BURNINGKIDDIES_LEVEL_H
#define BURNINGKIDDIES_LEVEL_H

#include <BurnEngine.h>
#include <vector>

namespace burnengine {

    class BackgroundEntity : public Entity {
    private:
        Tile* tile;

    public:
        BackgroundEntity(Tile& tile);
        Tile* getTile();
    };

    class LavaEntity : public Entity {
    private:
        Tile* tile;

    public:
        LavaEntity(Tile&);
        Tile* getTile();
    };

    class Level {
    private:
        BackgroundEntity* backgroundEntity = nullptr;
        LavaEntity* lavaEntity = nullptr;
        std::vector<burnengine::Entity*> environment;

        int width;
        int height;

    public:
        Level(int width, int height);

        inline int getWidth() { return width; }
        inline int getHeight() { return height; }

        void render(Game& game);
        void renderBackground(Game& game) const;

        void setBackground(BackgroundEntity& entity);
        void setLavaEntity(LavaEntity& lavaEntity);
        void addEnvironmentEntity(Entity& entity);

        void renderLava(Game& game);
    };

}

#endif
