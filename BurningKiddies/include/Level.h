#ifndef BURNINGKIDDIES_LEVEL_H
#define BURNINGKIDDIES_LEVEL_H

#include <BurnEngine.h>

namespace burnengine {

    class BackgroundEntity : public Entity {
    private:
        Tile* tile;

    public:
        BackgroundEntity(Tile& tile);
        Tile* getTile();
    };

    class Level {
    private:
        BackgroundEntity* backgroundEntity;
        int width;
        int height;

    public:
        Level(BackgroundEntity& backgroundEntity, int width, int height);

        inline int getWidth() { return width; }
        inline int getHeight() { return height; }

        void render(Game& game);
        void renderBackground(Game& game) const;
    };

}

#endif
