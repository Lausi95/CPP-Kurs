#ifndef TUTORIAL_ROOM_H
#define TUTORIAL_ROOM_H

#include <iostream>
#include "Entity.h"

enum Direction {
    DIR_NORTH,
    DIR_WEST,
    DIR_SOUTH,
    DIR_EAST
};

class Room : public Entity {
public:
    Room(Tile* tile, bool targetRoom);

    void setRoom(Direction, Room*);
    Tile* getTile();
    bool isTargetRoom();

    Room* move(Direction);

private:
    Tile* tile;
    bool targetRoom;
    Room* northRoom;
    Room* southRoom;
    Room* westRoom;
    Room* eastRoom;
};


#endif //TUTORIAL_ROOM_H
