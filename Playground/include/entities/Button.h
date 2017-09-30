#ifndef PLAYGROUND_BUTTON_H
#define PLAYGROUND_BUTTON_H

#include <Entity.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Button : public Entity {

    Tile* _tile;

public:

    Button(char* text, Tile* tile, float x, float y);

    Tile* getTile() override {
        return _tile;
    }

    void renderText(char* text);

};

#endif //PLAYGROUND_BUTTON_H
