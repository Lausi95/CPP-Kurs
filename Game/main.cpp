#include "stdafx.h"

int main(int argc, char** argv) {
    Window window("Das Drachenei", 1000, 700);

    Texture texture_desert_day("assets/cloudsinthedesert.png");
    Texture texture_desert_night("assets/desertnight.png");
    Texture texture_mountain("assets/coldmountain.png");
    Texture texture_fortress("assets/fortress.png");
    Texture texture_gate("assets/gate.png");
    Texture texture_guardtower("assets/guardtower.png");
    Texture texture_shore("assets/shore.png"); // Küste
    Texture texture_swamp("assets/sunsetintheswamp.png"); // Sumpf
    Texture texture_wizardtower("assets/wizardtower.png");

    Tile tile_desert_day(&texture_desert_day, 0, 0, 1000, 700);
    Tile tile_desert_night(&texture_desert_night, 0, 0, 1000, 700);
    Tile tile_mointain(&texture_mountain, 0, 0, 1000, 700);
    Tile tile_fortress(&texture_fortress, 0, 0, 1000, 700);
    Tile tile_gate(&texture_gate, 0, 0, 1000, 700);
    Tile tile_guardtower(&texture_guardtower, 0, 0, 1000, 700);
    Tile tile_shore(&texture_shore, 0, 0, 1000, 700);
    Tile tile_swamp(&texture_swamp, 0, 0, 1000, 700);
    Tile tile_wizardtower(&texture_wizardtower, 0, 0, 1000, 700);

    Room room_desert_day(&tile_desert_day, false);
    Room room_desert_night(&tile_desert_night, false);
    Room room_mountain(&tile_mointain, false);
    Room room_fortress(&tile_fortress, false);
    Room room_gate(&tile_gate, false);
    Room room_guardtower(&tile_guardtower, false);
    Room room_shore(&tile_shore, false);
    Room room_swamp(&tile_swamp, false);
    Room room_wizardtower(&tile_wizardtower, true);

    room_gate.setRoom(DIR_EAST, &room_fortress);
    room_fortress.setRoom(DIR_SOUTH, &room_desert_night);
    room_desert_night.setRoom(DIR_SOUTH, &room_desert_day);
    room_desert_day.setRoom(DIR_SOUTH, &room_shore);
    room_desert_day.setRoom(DIR_EAST, &room_mountain);
    room_mountain.setRoom(DIR_EAST, &room_swamp);
    room_mountain.setRoom(DIR_SOUTH, &room_guardtower);
    room_shore.setRoom(DIR_EAST, &room_guardtower);
    room_guardtower.setRoom(DIR_SOUTH, &room_wizardtower);

    Room* currentRoom = &room_gate;

    InputHandler inputHandler;
    bool running = true;
    Timer timer;

    while (running) {
        // render
        window.render(currentRoom);

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

            if (inputHandler.isQuitEvent()) {
                INFO("Quit event triggered")
                running = false;
            }
        }
        // update

        window.update();
        timer.sleep(16);
        timer.update();
    }

    return 0;
}
