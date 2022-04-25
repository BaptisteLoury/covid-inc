#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "utils/MapUtils.hpp"

MapUtils::MapUtils() : _pathToParamFile("map"), _lines(44), _colums(226) {
    readMapFile();
}

void MapUtils::readMapFile() {
    vector<string> map;

    ifstream mapFile(_pathToParamFile);

    string line;

    while(getline(mapFile, line)) {
        map.push_back(line);
    }

    _mapTable = map;
}

vector<string> MapUtils::getMapTable() {
    return _mapTable;
}