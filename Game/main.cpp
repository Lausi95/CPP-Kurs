#include "logging.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** args) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window *win = SDL_CreateWindow("Hallo Welt", 100, 100, 300, 300, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    SDL_Surface *png = IMG_Load("tiles.png");

    SDL_BlitSurface(png, NULL, surf, NULL);
    SDL_UpdateWindowSurface(win);

    SDL_Delay(2000);

    return 0;
}