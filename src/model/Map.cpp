#include "model/Map.hpp"

Map::Map() {}

Map::Map(std::vector<std::string> charMap) {
    for(int i=0; i < charMap.size(); i++) {
        const char * line = charMap[i].c_str();
        std::vector<AbstractTile *> tLine;
        for(int y=0; y < charMap[i].size(); y++) {
            addTile(i,y,tLine);
        }
        _tiles.push_back(tLine);
    }
}

void Map::addTile(int x, int y, char c, std::vector<AbstractTile *>& v) {
    switch (c)
    {
    case ':':
        v.push_back(new LandTile(x,y));
        break;
    default:
        v.push_back(new OceanTile(x,y));
        break;
    }
}