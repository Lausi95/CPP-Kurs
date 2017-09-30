#include <MenuFactory.h>
#include <entities/SimpleEntity.h>
#include <entities/Button.h>
#include <GlobalSettings.h>

Texture wallpaperTexture("assets/images/backgrounds/wallpaper.png");
Tile wallpaperTile(&wallpaperTexture, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
SimpleEntity wallpaperEntity(&wallpaperTile, 0, 0);

std::vector<Entity*> entities {
        &wallpaperEntity
};

Menu MenuFactory::getMenu(Camera* camera,
                          Input* input,
                          SoundSystem* soundSystem,
                          std::vector<Button*> buttons) {

    //append buttons to entities
    entities.insert(entities.end(), buttons.begin(), buttons.end());

    return Menu(camera, entities, buttons, input, soundSystem);
}
