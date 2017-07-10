#ifndef PUNKTEFRESSER_LEVEL_H
#define PUNKTEFRESSER_LEVEL_H

#include <vector>

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
    void setFieldAt(int row, int col, Field field);

    Field operator()(int row, int col) {
        return getFieldAt(row, col);
    }

private:
    int rowCount;
    int columnCount;
    std::vector<Field>* fields;

    LevelMap(int rowCount, int columnCount, std::vector<Field>* fields);
};

#endif //PUNKTEFRESSER_LEVEL_H
