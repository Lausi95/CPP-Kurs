#include "LevelMap.h"

#include <string>
#include <iostream>
#include <fstream>

struct FieldMap {
    Field map[255];

    FieldMap() {
        for (int i = 0; i < 255; i++)
            map[i] = Field::EMPTY;
        map['#'] = Field::WALL;
        map['P'] = Field::PLAYER;
        map['E'] = Field::ENEMY;
        map['F'] = Field::FRUIT;
    }

    Field operator[](char c) {
        return map[c];
    }
} fieldMap;

LevelMap::LevelMap(int rowCount, int columnCount, std::vector<Field> fields) {
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    this->fields = fields;
}

int LevelMap::getRowCount() {
    return this->rowCount;
}

int LevelMap::getColumnCount() {
    return this->columnCount;
}

Field LevelMap::fieldAt(int row, int col) {
    int index = row * this->columnCount + col;
    return this->fields[index];
}

void loadLine(const std::string &line, std::vector<Field> &fields) {
    for (char c : line)
        fields.push_back(fieldMap[c]);
}

LevelMap LevelMap::load(const char *path) {
    std::ifstream filestream(path);
    std::string line;

    int colCount = 0;
    int rowCount = 0;
    std::vector<Field> fields;

    while (!filestream.eof()) {
        std::getline(filestream, line);
        loadLine(line, fields);
        colCount = (int) line.length();
        rowCount++;
    }

    filestream.close();
    return LevelMap(rowCount, colCount, fields);
}
