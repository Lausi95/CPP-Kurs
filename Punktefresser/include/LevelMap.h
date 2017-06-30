#ifndef PUNKTEFRESSER_LEVEL_H
#define PUNKTEFRESSER_LEVEL_H

#include <vector>

enum class Field {
    EMPTY,
    WALL,
    PLAYER,
    FRUIT,
    ENEMY
};

class LevelMap {
public:
    static LevelMap load(const char* path);

    int getRowCount();
    int getColumnCount();

    Field fieldAt(int row, int col);

    Field operator()(int row, int col) {
        return fieldAt(row, col);
    }

private:
    int rowCount;
    int columnCount;
    std::vector<Field> fields;

    LevelMap(int rowCount, int columnCount, std::vector<Field> fields);
};

#endif //PUNKTEFRESSER_LEVEL_H
