#ifndef PUNKTEFRESSER_LEVEL_H
#define PUNKTEFRESSER_LEVEL_H

#include <vector>
#include "Direction.h"

enum class Field {
    FloorWithPoint,
    Floor,
    Wall,
    Player,
    Fruit,
    Enemy
};

class LevelMap {
public:
    static LevelMap load(const char* path);

    int getRowCount();
    int getColumnCount();

    Field getFieldAt(int row, int col);
    Field operator()(int row, int col);
    Field nextField(int col, int row, Direction direction);

    void setField(int row, int col, Field field);

private:
    int rowCount;
    int columnCount;
    std::vector<Field>* fields;

    LevelMap(int rowCount, int columnCount, std::vector<Field>* fields);
};

Field nextField(LevelMap& map, int x, int y, Direction direction);

#endif //PUNKTEFRESSER_LEVEL_H
