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

Texture buttonTexture1("assets/images/backgrounds/sky.png");
Texture buttonTexture2("assets/images/backgrounds/sky.png");
Texture buttonTexture3("assets/images/backgrounds/sky.png");
Tile buttonTile1(&buttonTexture1, 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
Tile buttonTile2(&buttonTexture2, 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
Tile buttonTile3(&buttonTexture3, 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);

int x = (WINDOW_WIDTH / 2) - (BUTTON_WIDTH / 2);
int y = (WINDOW_HEIGHT - (2 * VERTICAL_MARGIN)) / BUTTON_COUNT;
Button startButton("Start", &buttonTile1, x, y*1);
Button changeSkinButton("Change Skin", &buttonTile2, x, y*2);
Button muteButton("Mute", &buttonTile3, x, y*3);


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
