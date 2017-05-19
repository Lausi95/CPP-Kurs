//
// Created by tom on 05.05.17.
//

#include "TextAdventure.h"
#include "Room.h"

#include <iostream>
using namespace std;

void runTextAdventure() {
    Room startRoom("Start Raum", false);
    Room desert("Du befindest dich in der Wüste. Die Sonne brennt unbarmherzig.", false);
    Room targetRoom("Ziel Raum", true);

    startRoom.setRoom(DIR_SOUTH, &desert);
    desert.setRoom(DIR_EAST, &targetRoom);

    Room* currentRoom = &startRoom;
    while (!currentRoom->isTargetRoom()) {
        cout << currentRoom->getDescription() << endl;
        cout << "Wo hin willst du als nächstes? (N, S, O, W): ";

        char dir;
        cin >> dir;
        dir = (char)toupper(dir);

        switch (dir) {
            case 'N':
                currentRoom = currentRoom->move(DIR_NORTH);
                break;
            case 'S':
                currentRoom = currentRoom->move(DIR_SOUTH);
                break;
            case 'O':
                currentRoom = currentRoom->move(DIR_EAST);
                break;
            case 'W':
                currentRoom = currentRoom->move(DIR_WEST);
                break;
            default:
                cout << "Du kannst nur nach (N, S, O, W) gehen!" << endl;
        }

        cout << endl;
    }

    cout << currentRoom->getDescription() << endl;
}
