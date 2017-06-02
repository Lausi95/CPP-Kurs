#include "stdafx.h"


#define ROOM_DESERT_DAY   0
#define ROOM_DESERT_NIGHT 1
#define ROOM_MOUNTAIN     2
#define ROOM_FORTRESS     3
#define ROOM_GATE         4
#define ROOM_GUARDTOWER   5
#define ROOM_SHORE        6
#define ROOM_SWAMP        7
#define ROOM_WIZARDTOWER  8

#define ROOM_AMOUNT 9


class Item : public Entity {
private:
    Tile* tile;

public:
    Item(Tile* tile, float x, float y);
    Tile* getTile();
};

Item::Item(Tile* tile, float x, float y) : Entity(x, y) {
    this->tile = tile;
}

Tile *Item::getTile() {
    return tile;
}

struct GameState {
    bool chestFound = false;
    bool talkedToMage = false;
    bool eggFound = false;
};

int main(int argc, char** argv) {
    Window window("Das Drachenei", 1000, 700);

    Texture texture_desert_day("assets/rooms/cloudsinthedesert.png");
    Texture texture_desert_night("assets/rooms/desertnight.png");
    Texture texture_mountain("assets/rooms/coldmountain.png");
    Texture texture_fortress("assets/rooms/fortress.png");
    Texture texture_gate("assets/rooms/gate.png");
    Texture texture_guardtower("assets/rooms/guardtower.png");
    Texture texture_shore("assets/rooms/shore.png"); // Küste
    Texture texture_swamp("assets/rooms/sunsetintheswamp.png"); // Sumpf
    Texture texture_wizardtower("assets/rooms/wizardtower.png");

    Texture texture_chest("assets/items/chest.png");
    Texture texture_scroll("assets/items/scroll.png");
    Texture texture_mage("assets/items/ryze.png");
    Texture texture_dragonegg("assets/items/dragonegg.png");

    Tile tile_desert_day(&texture_desert_day, 0, 0, 1000, 700);
    Tile tile_desert_night(&texture_desert_night, 0, 0, 1000, 700);
    Tile tile_mointain(&texture_mountain, 0, 0, 1000, 700);
    Tile tile_fortress(&texture_fortress, 0, 0, 1000, 700);
    Tile tile_gate(&texture_gate, 0, 0, 1000, 700);
    Tile tile_guardtower(&texture_guardtower, 0, 0, 1000, 700);
    Tile tile_shore(&texture_shore, 0, 0, 1000, 700);
    Tile tile_swamp(&texture_swamp, 0, 0, 1000, 700);
    Tile tile_wizardtower(&texture_wizardtower, 0, 0, 1000, 700);

    Tile tile_chest(&texture_chest, 0, 0, 161, 111);
    Tile tile_scroll(&texture_scroll, 0, 0, 128, 128);
    Tile tile_mage(&texture_mage, 0, 0, 599, 500);
    Tile tile_dragonegg(&texture_dragonegg, 0, 0, 118, 135);

    srand(time(NULL));
    int x = rand() % (window.getWidth() - tile_scroll.getRekt()->w);
    int y = rand() % (window.getHeight() - tile_scroll.getRekt()->h);

    Item item_chest(&tile_chest, x, y);
    Item item_scroll(&tile_scroll, 0, window.getHeight() - tile_scroll.getRekt()->h);
    Item item_mage(&tile_mage, window.getHeight() - tile_mage.getRekt()->h, (window.getWidth() - tile_mage.getRekt()->w) / 2);

    x = rand() % (window.getWidth() - tile_scroll.getRekt()->w);
    y = rand() % (window.getHeight() - tile_scroll.getRekt()->h);
    Item item_dragonegg(&tile_dragonegg, x, y);

    Room rooms[] = {
            Room(&tile_desert_day, false, "Wüste bei Tag"),
            Room(&tile_desert_night, false, "Wüste bei Nacht"),
            Room(&tile_mointain, false, "Auf dem Berggipfel"),
            Room(&tile_fortress, false, "In der Festung"),
            Room(&tile_gate, false, "Am Tor"),
            Room(&tile_guardtower, false, "Am Turm"),
            Room(&tile_shore, false, "An der Küste"),
            Room(&tile_swamp, false, "Im Sumpf"),
            Room(&tile_wizardtower, true, "Magierturm"), // last room in array has to be the wizard room
    };

    rooms[ROOM_GATE].setRoom(DIR_EAST, &rooms[ROOM_FORTRESS]);
    rooms[ROOM_FORTRESS].setRoom(DIR_SOUTH, &rooms[ROOM_DESERT_NIGHT]);
    rooms[ROOM_DESERT_NIGHT].setRoom(DIR_SOUTH, &rooms[ROOM_DESERT_DAY]);
    rooms[ROOM_DESERT_DAY].setRoom(DIR_SOUTH, &rooms[ROOM_SHORE]);
    rooms[ROOM_DESERT_DAY].setRoom(DIR_EAST, &rooms[ROOM_MOUNTAIN]);
    rooms[ROOM_MOUNTAIN].setRoom(DIR_EAST, &rooms[ROOM_SWAMP]);
    rooms[ROOM_MOUNTAIN].setRoom(DIR_SOUTH, &rooms[ROOM_GUARDTOWER]);
    rooms[ROOM_SHORE].setRoom(DIR_EAST, &rooms[ROOM_GUARDTOWER]);
    rooms[ROOM_GUARDTOWER].setRoom(DIR_SOUTH, &rooms[ROOM_WIZARDTOWER]);

    Room* currentRoom = &rooms[ROOM_GATE];
    Room* roomWithChest = &rooms[rand() % (ROOM_AMOUNT - 1)];
    Room* roomWithDragonEgg = &rooms[rand() % ROOM_AMOUNT];

    InputHandler inputHandler;
    bool running = true;
    Timer timer;
    GameState gameState;

    while (running) {
        // renderEntity
        window.renderEntity(currentRoom);
        if (currentRoom == roomWithChest && !gameState.chestFound) {
            window.renderEntity(&item_chest);
        }
        if (currentRoom == &rooms[ROOM_WIZARDTOWER] && !gameState.talkedToMage) {
            window.renderEntity(&item_mage);
        }
        if (currentRoom == roomWithDragonEgg && gameState.talkedToMage && gameState.chestFound) {
            window.renderEntity(&item_dragonegg);
        }
        if (gameState.chestFound && !gameState.talkedToMage) {
            window.renderEntity(&item_scroll);
        }

        // input
        while (inputHandler.pollEvent()) {
            if (inputHandler.isKeyPressed(SDLK_w)) {
                currentRoom = currentRoom->move(DIR_NORTH);
            }
            if (inputHandler.isKeyPressed(SDLK_a)) {
                currentRoom = currentRoom->move(DIR_WEST);
            }
            if (inputHandler.isKeyPressed(SDLK_s)) {
                currentRoom = currentRoom->move(DIR_SOUTH);
            }
            if (inputHandler.isKeyPressed(SDLK_d)) {
                currentRoom = currentRoom->move(DIR_EAST);
            }

            if (inputHandler.isMouseDown()) {
                int mx = inputHandler.getMouseX();
                int my = inputHandler.getMouseY();

                if (!gameState.chestFound && currentRoom == roomWithChest && currentRoom->pointInside(mx, my)) {
                    gameState.chestFound = true;
                }

                if (gameState.chestFound && !gameState.talkedToMage && currentRoom == &rooms[ROOM_WIZARDTOWER] && item_mage.pointInside(mx, my)) {
                    gameState.talkedToMage = true;
                }

                if (gameState.chestFound && gameState.talkedToMage && currentRoom == roomWithDragonEgg && item_dragonegg.pointInside(mx, my)) {
                    running = false;
                }
            }

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }
        // update

        window.renderText(currentRoom->getDescription());
        window.update();
        timer.sleep(16);
        timer.update();
    }

    return 0;
}
