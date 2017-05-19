#include "Room.h"

#include <iostream>

Room::Room(std::string description, bool targetRoom) {
    this->description = description;
    this->targetRoom = targetRoom;

    this->southRoom = NULL;
    this->eastRoom  = NULL;
    this->westRoom  = NULL;
    this->northRoom = NULL;
}

Room *Room::move(Direction direction) {
    Room* target = NULL;
    switch (direction) {
        case DIR_NORTH:
            target = this->northRoom;
            break;
        case DIR_EAST:
            target = this->eastRoom;
            break;
        case DIR_WEST:
            target = this->westRoom;
            break;
        case DIR_SOUTH:
            target = this->southRoom;
            break;
        default:
            std::cout << "In diese Richtung kann man nicht gehen" << std::endl;
    }
    if (target == NULL) {
        std::cout << "Da gibt es nichts!" << std::endl;
        target = this;
    }
    return target;
}

void Room::setRoom(Direction direction, Room* room) {
    switch (direction) {
        case DIR_NORTH:
            this->northRoom = room;
            room->southRoom = this;
            break;
        case DIR_EAST:
            this->eastRoom = room;
            room->westRoom = this;
            break;
        case DIR_WEST:
            this->westRoom = room;
            room->eastRoom = this;
            break;
        case DIR_SOUTH:
            this->southRoom = room;
            room->northRoom = this;
            break;
        default:
        std::cerr << "In diese Richtung kann kein Raum eingetragen werden!" << std::endl;
    }
}

bool Room::isTargetRoom() {
    return this->targetRoom;
}

std::string Room::getDescription() {
    return this->description;
}
