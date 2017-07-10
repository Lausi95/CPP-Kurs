#include "LevelMap.h"

#include <string>
#include <iostream>
#include <fstream>

struct FieldMap {
    Field map[255];

    FieldMap() {
        for (int i = 0; i < 255; i++)
            map[i] = Field::FloorWithPoint;
        map['#'] = Field::Wall;
        map['P'] = Field::Player;
        map['E'] = Field::Enemy;
        map['F'] = Field::Fruit;
    }

    Field operator[](char c) {
        return map[c];
    }
} fieldMap;

LevelMap::LevelMap(int rowCount, int columnCount, std::vector<Field>* fields) {
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

Field LevelMap::getFieldAt(int col, int row) {
    int index = row * columnCount + col;
    return (*fields)[index];
}

void LevelMap::setFieldAt(int col, int row, Field field) {
    int index = row * columnCount + col;
    (*fields)[index] = field;
}

void loadLine(const std::string &line, std::vector<Field>* fields) {
    for (char c : line)
        fields->push_back(fieldMap[c]);
}

LevelMap LevelMap::load(const char *path) {
    std::ifstream filestream(path);
    std::string line;

    int colCount = 0;
    int rowCount = 0;
    std::vector<Field>* fields = new std::vector<Field>();

    while (!filestream.eof()) {
        std::getline(filestream, line);
        loadLine(line, fields);
        colCount = (int) line.length();
        rowCount++;
    }

    filestream.close();
    return LevelMap(rowCount, colCount, fields);
}
