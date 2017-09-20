#include <BurnEngine.h>

void ::burnengine::initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

burnengine::Game::Game(const char *title, int width, int height) {
    wnd = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_SHOWN);
    wnd_surface = SDL_GetWindowSurface(wnd);

    for (int i = 0; i < 1024; i++) {
        keys[i] = false;
    }
}

burnengine::Game::~Game() {
    SDL_DestroyWindow(wnd);
}

void burnengine::Game::update() {
    ticks++;

    while (SDL_PollEvent(&event)) {
        int code = (int)event.key.keysym.sym;
        if (code < 1024) {
            if (event.type == SDL_KEYDOWN) {
                keys[code] = true;
            }
            if (event.type == SDL_KEYUP) {
                keys[code] = false;
            }
        }

        running = running && event.type != SDL_QUIT;
    }

    SDL_UpdateWindowSurface(wnd);
}

void burnengine::Game::resetTicks() {
    ticks = 0;
}

bool burnengine::Game::isKeyDown(const SDL_Keycode& keycode) const {
    return keys[keycode];
}

burnengine::Texture::Texture(const char *file, int cellWidth, int cellHeight)
        : cellWidth(cellWidth), cellHeight(cellHeight) {
    surface = IMG_Load(file);
}

burnengine::Texture::~Texture() {
    SDL_FreeSurface(surface);
}

burnengine::Tile::Tile(burnengine::Texture &texture, int cell_x, int cell_y, int cell_w, int cell_h) {
    this->texture = &texture;
    this->rect = std::make_unique<SDL_Rect>();
    this->rect->x = cell_x * this->texture->cellWidth;
    this->rect->y = cell_y * this->texture->cellHeight;
    this->rect->w = cell_w * this->texture->cellWidth;
    this->rect->h = cell_h * this->texture->cellHeight;
}

void burnengine::Screen::addEntity(burnengine::Entity* entity) {
    entities.push_back(entity);
}
