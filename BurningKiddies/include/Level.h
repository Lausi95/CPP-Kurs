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

        inline int getWidth() const { return width; }
        inline int getHeight() const { return height; }

        void render(Game& game) const;

        void setBackground(BackgroundEntity& entity);
        void setLavaEntity(LavaEntity& lavaEntity);
        void addEnvironmentEntity(Entity& entity);

    private:
        void renderLava(Game& game) const;
        void renderLavaChunk(Game& game, int x) const;
        void renderBackground(Game& game) const;
        void renderBackgroundChunk(Game& game, int x, int y) const;
    };

}

#endif
