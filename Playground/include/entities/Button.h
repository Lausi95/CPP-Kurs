#ifndef PLAYGROUND_BUTTON_H
#define PLAYGROUND_BUTTON_H

#include <Entity.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Button : public Entity {

    Tile* _tile;
    char* _text;

    int _width, _height;

public:

    Button(char* text, int width, int height, float x, float y);

    Tile* getTile() override {
        return _tile;
    }

    void renderText(char* text);

    void setHovered(bool hovered);


};

#endif //PLAYGROUND_BUTTON_H
