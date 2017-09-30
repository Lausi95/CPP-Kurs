#ifndef PLAYGROUND_BUTTON_H
#define PLAYGROUND_BUTTON_H

#include <Entity.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Button : public Entity {

    Tile* _tile;
    char* _text;

    int _width, _height;
    bool _hovered = false;

public:

    Button(void (*onclick)(void), int width, int height, float x, float y);

    Tile* getTile() override {
        return _tile;
    }

    void setText(char* text);
    void renderText(char* text);
    void setHovered(bool hovered);
    void draw();
    void (*_onclick)(void);
};

#endif //PLAYGROUND_BUTTON_H
