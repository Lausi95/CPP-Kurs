//
// Created by hendrik on 29.09.17.
//

#include <MenuFactory.h>
#include <entities/SimpleEntity.h>
#include <entities/Button.h>

Texture wallpaperTexture("assets/images/backgrounds/wallpaper.png");
Tile wallpaperTile(&wallpaperTexture, 0, 0, 800, 608);
SimpleEntity wallpaperEntity(&wallpaperTile, 0, 0);

Texture buttonTexture("assets/images/backgrounds/wallpaper.png");
Tile buttonTile(&buttonTexture, 0, 0, 200, 50);
Button startButton("Start", &buttonTile, 0, 0);
Button changeSkinButton("Change Skin", &buttonTile, 60, 0);
Button muteButton("Mute", &buttonTile, 120, 0);


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
