#ifndef BURNINGKIDDIES_BURNENGINE_H
#define BURNINGKIDDIES_BURNENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <memory>

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


    class Entity {
    private:
        std::unique_ptr<SDL_Rect> rect;

    public:
        Entity(int x, int y);

        virtual Tile* getTile() = 0;
        inline SDL_Rect* getRect() { return rect.get(); }

        virtual inline int getX() { return rect->x; }
        virtual inline int getY() { return rect->y; }
        virtual inline int getWidth() { return getTile()->getRect()->w; }
        virtual inline int getHeight() { return getTile()->getRect()->h; }

        void setX(int x);
        void setY(int y);
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

        void render(Entity& entity);
        void resetTicks();

        bool isKeyDown(const SDL_Keycode& keycode) const;
    };

}

#endif
