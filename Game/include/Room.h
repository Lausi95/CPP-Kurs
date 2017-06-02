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
    Room(Tile* tile, bool targetRoom, std::string descritpion);

    void setRoom(Direction, Room*);
    Tile* getTile();
    std::string getDescription();
    bool isTargetRoom();

    Room* move(Direction);

private:
    Tile* tile;
    bool targetRoom;
    Room* northRoom;
    Room* southRoom;
    Room* westRoom;
    Room* eastRoom;

    std::string description;
};


#endif //TUTORIAL_ROOM_H
