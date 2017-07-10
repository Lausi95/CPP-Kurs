#ifndef PUNKTEFRESSER_DIRECTION_H
#define PUNKTEFRESSER_DIRECTION_H

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

Direction oppositeDirection(Direction direction);

#endif
