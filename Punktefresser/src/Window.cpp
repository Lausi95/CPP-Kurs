#include "stdafx.h"

bool sdlInitialized = false;

Window::Window(const char *title, int width, int height) {
    this->title = title;
    this->width = width;
    this->height = height;

    if (!sdlInitialized) {
        INFO("Initializing SDL")
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        TTF_Init();
        sdlInitialized = true;
    }

    INFO("Creating SDL Window")
    this->sdlWindow = SDL_CreateWindow(this->title, 200, 200, this->width, this->height, SDL_WINDOW_SHOWN);

    INFO("Getting Surface from Window")
    this->sdlSurface = SDL_GetWindowSurface(this->sdlWindow);
}

void Window::update() {
    SDL_UpdateWindowSurface(this->sdlWindow);
}

void Window::renderText(std::string text) {

    TTF_Font* font = TTF_OpenFont("arial.ttf", 20);
    if(!font) {
        std::cerr << "Konnte Schriftart nicht laden! Fehler: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Color color = {255, 255, 255};

    SDL_Surface* surfaceMessage = TTF_RenderUTF8_Solid(font, text.c_str(), color);

    SDL_Rect* message_rect = new SDL_Rect();
    message_rect->x = 0;
    message_rect->y = 0;
    message_rect->w = 200;
    message_rect->h = 200;

    SDL_BlitSurface(surfaceMessage, message_rect, sdlSurface, message_rect);

    TTF_CloseFont(font);
}

int Window::getWidth() {
    return this->width;
}

int Window::getHeight() {
    return this->height;
}
