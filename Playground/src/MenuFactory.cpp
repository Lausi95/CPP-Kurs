#include <MenuFactory.h>
#include <entities/SimpleEntity.h>
#include <entities/Button.h>
#include <GlobalSettings.h>

Texture wallpaperTexture("assets/images/backgrounds/wallpaper.png");
Tile wallpaperTile(&wallpaperTexture, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
SimpleEntity wallpaperEntity(&wallpaperTile, 0, 0);

int x = (WINDOW_WIDTH / 2) - (BUTTON_WIDTH / 2);
int y = (WINDOW_HEIGHT - (2 * VERTICAL_MARGIN)) / BUTTON_COUNT;
Button startButton("Start", BUTTON_WIDTH, BUTTON_HEIGHT, x, y*1);
Button changeSkinButton("Change Skin", BUTTON_WIDTH, BUTTON_HEIGHT, x, y*2);
Button muteButton("Mute", BUTTON_WIDTH, BUTTON_HEIGHT, x, y*3);

std::vector<Entity*> entities {
        &wallpaperEntity,
        &startButton, &changeSkinButton, &muteButton
};

Menu MenuFactory::getMenu(Camera* camera,
                          Input* input,
                          SoundSystem* soundSystem,
                          void (*callbackChangeWorld)(Worlds)) {

    startButton.highlight();

    return Menu(camera, entities, input, soundSystem, callbackChangeWorld);
}
