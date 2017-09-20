#ifndef BURNINGKIDDIES_BURNENGINE_H
#define BURNINGKIDDIES_BURNENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <memory>
#include <vector>

namespace burnengine {

    void initialize();


    struct Texture {
        SDL_Surface* surface;
        int cellWidth;
        int cellHeight;

        Texture(const char* file, int cellWidth, int cellHeight);
        ~Texture();
    };


    class Tile {
    private:
        Texture* texture;
        std::unique_ptr<SDL_Rect> rect;

    public:
        Tile(Texture& texture, int cell_x, int cell_y, int cell_w = 1, int cell_h = 1);

        inline Texture* getTexture() { return texture; }
        inline SDL_Rect* getRect() { return rect.get(); }
    };


    template<typename T>
    class Entity {
    private:
        T x, y;
        int w, h;
        std::unique_ptr<SDL_Rect> rect;

    public:
        Entity(T x, T y)  {
            this->rect = std::make_unique<SDL_Rect>();
            this->x = x;
            this->y = y;
        }

        virtual Tile* getTile() = 0;
        inline SDL_Rect* getRect() {
            rect->x = (int)x;
            rect->y = (int)y;
            return rect.get();
        }

        virtual inline T getX() { return x; }
        virtual inline T getY() { return y; }
        virtual inline int getWidth() { return getTile()->getRect()->w; }
        virtual inline int getHeight() { return getTile()->getRect()->h; }

        inline void setX(T x) {
            this->x = x;
        }
        inline void setY(T y) {
            this->y = y;
        }
    };

    class Screen {
    private:
        std::vector<Entity*> entities;

    public:
        void addEntity(Entity* entity);
        inline std::vector<Entity*> getEntities() { return entities; }
    };

    class Game {
    private:
        SDL_Window* wnd;
        SDL_Surface* wnd_surface;
        SDL_Event event;
        bool running = true;
        unsigned long long ticks = 0;

        bool keys[1024];

    public:
        Game(const char* title, int width, int height);
        ~Game();

        void update();
        inline bool isRunning() const { return running; }
        inline const unsigned long long getTicks() const { return ticks; }

        template <typename T>
        void render(Screen* screen) {
            for (Entity* entity : screen->getEntities())
                SDL_BlitSurface(entity->getTile()->getTexture()->surface, entity->getTile()->getRect(), wnd_surface, entity->getRect());
        }

        void resetTicks();

        bool isKeyDown(const SDL_Keycode& keycode) const;
    };

}

#endif
