#ifndef TUTORIAL_ROOM_H
#define TUTORIAL_ROOM_H

#include <iostream>

enum Direction {
    DIR_NORTH,
    DIR_WEST,
    DIR_SOUTH,
    DIR_EAST
};

class Room {
public:
    Room(std::string description, bool targetRoom);

    void setRoom(Direction, Room*);
    std::string getDescription();
    bool isTargetRoom();

    Room* move(Direction);

private:
    std::string description;
    bool targetRoom;
    Room* northRoom;
    Room* southRoom;
    Room* westRoom;
    Room* eastRoom;
};


#endif //TUTORIAL_ROOM_H
