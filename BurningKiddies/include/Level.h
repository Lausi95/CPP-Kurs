#ifndef BURNINGKIDDIES_LEVEL_H
#define BURNINGKIDDIES_LEVEL_H

#include <BurnEngine.h>
#include <vector>

namespace burnengine {

    class BackgroundEntity : public Entity<int> {
    private:
        Tile* tile;

    public:
        BackgroundEntity(Tile& tile);
        Tile* getTile();
    };

    class LavaEntity : public Entity<int> {
    private:
        Tile* tile;

    public:
        LavaEntity(Tile&);
        Tile* getTile();
    };

    class Level : public Screen {
    private:
        BackgroundEntity* backgroundEntity = nullptr;
        LavaEntity* lavaEntity = nullptr;
        std::vector<burnengine::Entity<int>*> environment;

        int width;
        int height;

    public:
        Level(int width, int height);

        inline int getWidth() const { return width; }
        inline int getHeight() const { return height; }

        void setBackground(BackgroundEntity& entity);
        void setLavaEntity(LavaEntity& lavaEntity);
        void addEnvironmentEntity(Entity<int>& entity);
    };

}

#endif
