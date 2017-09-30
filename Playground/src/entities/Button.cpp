#include <entities/Button.h>

Button::Button(char* text, Tile* tile, float x, float y) : Entity(x, y, tile->getWidth(), tile->getHeight()) {

    _tile = tile;

    TTF_Init();
    renderText(text);
}


void Button::renderText(char *text) {

    TTF_Font* font = TTF_OpenFont("arial.ttf", 18);
    if(!font) {
        std::cerr << "Konnte Schriftart nicht laden! Fehler: " << TTF_GetError() << std::endl;
        return;
    }

    Tile* buttonTile = getTile();

    SDL_Surface* buttonSurface = getTile()->getTexture()->getSurface();

    SDL_Color color = {255, 255, 255};
    SDL_Surface* surfaceMessage = TTF_RenderUTF8_Solid(font, text, color);

    SDL_Rect* message_rect = new SDL_Rect();
    message_rect->x = (buttonTile->getWidth() / 2) - (surfaceMessage->w / 2);
    message_rect->y = (buttonTile->getHeight() / 2) - (surfaceMessage->h / 2);
    message_rect->w = surfaceMessage->w;
    message_rect->h = surfaceMessage->h;



    SDL_BlitSurface(surfaceMessage, &surfaceMessage->clip_rect, buttonSurface, message_rect);

    TTF_CloseFont(font);
}
