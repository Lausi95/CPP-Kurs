//
// Created by hendrik on 29.09.17.
//

#include <MenuFactory.h>
#include <entities/SimpleEntity.h>
#include <entities/Button.h>
#include <GlobalSettings.h>

Texture wallpaperTexture("assets/images/backgrounds/wallpaper.png");
Tile wallpaperTile(&wallpaperTexture, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
SimpleEntity wallpaperEntity(&wallpaperTile, 0, 0);

Texture buttonTexture("assets/images/backgrounds/sky.png");
Tile buttonTile(&buttonTexture, 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);

int x = (WINDOW_WIDTH / 2) - (BUTTON_WIDTH / 2);
int y = (WINDOW_HEIGHT - (2 * VERTICAL_MARGIN)) / BUTTON_COUNT;
Button startButton("Start", &buttonTile, x, y*1);
Button changeSkinButton("Change Skin", &buttonTile, x, y*2);
Button muteButton("Mute", &buttonTile, x, y*3);


std::vector<Entity*> entities {
        &wallpaperEntity,
        &startButton, &changeSkinButton, &muteButton
};

Menu MenuFactory::getMenu(Camera* camera,
                          Input* input,
                          SoundSystem* soundSystem,
                          void (*callbackChangeWorld)(Worlds)) {

    return Menu(camera, entities, input, soundSystem, callbackChangeWorld);
}
