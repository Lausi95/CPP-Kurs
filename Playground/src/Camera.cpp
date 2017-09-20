#include <Camera.h>

bool sdlInitialized = false;

Camera::Camera(int width, int height, const char* title) {
    if (!sdlInitialized) {
        SDL_Init(SDL_INIT_VIDEO);
        sdlInitialized = true;
    }

    _width = width;
    _height = height;
    _offsetX = _offsetY = 0;

    _window = SDL_CreateWindow(title, 300, 300, width, height, SDL_WINDOW_SHOWN);
    _surface = SDL_GetWindowSurface(_window);
}

void Camera::setOffsetX(int offset) {
    _offsetX = offset;
}

void Camera::setOffsetY(int offset) {
    _offsetY = offset;
}

void Camera::setOffset(int offsetX, int offsetY) {
    setOffsetX(offsetX);
    setOffsetY(offsetY);
}

void Camera::lockOn(Entity* entity) {
    setOffsetX((int) (entity->getX() + entity->getWidth()  / 2));
    setOffsetY((int) (entity->getY() + entity->getHeight() / 2));
}

void Camera::clear() {
    SDL_FillRect(_surface, NULL, 0x000000);
}

void Camera::show(Entity* entity) {
    SDL_Surface* texture      = entity->getTile()->getTexture()->getSurface();
    SDL_Rect textureRectangle = entity->getTile()->getRectangle()->toSDLRect();
    SDL_Rect entityRect       = entity->getRectangle()->toSDLRect();

    entityRect.x += _width  / 2 - _offsetX;
    entityRect.y += _height / 2 - _offsetY;

    SDL_BlitSurface(texture, &textureRectangle, _surface, &entityRect);
}

void Camera::update() {
    SDL_UpdateWindowSurface(_window);
}
