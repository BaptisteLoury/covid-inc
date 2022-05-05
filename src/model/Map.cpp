#include <ctype.h>
#include "model/Map.hpp"

Map::Map() {}

Map::Map(std::vector<std::string> charMap) {
    for(int i=0; i < charMap.size(); i++) {
        const char * line = charMap[i].c_str();
        std::vector<AbstractTile *> tLine;
        for(int y=0; y < charMap[i].size(); y++) {
            addTile(i,y,line[y],tLine);
        }
        _tiles.push_back(tLine);
    }
}

void Map::addTile(int x, int y, char c, std::vector<AbstractTile *>& v) {
    if(c == ':') {
        v.push_back(new LandTile(x,y));
    }
    else if(isalpha(c)) {
        char * tileC = new char[2];
        tileC[0] = c;
        tileC[1] = '\0';
        v.push_back(new CityTile(x,y,tileC));
    }
    else if(isdigit(c)) {
        char * tileC = new char[2];
        tileC[0] = c;
        tileC[1] = '\0';
        v.push_back(new SpawnTile(x,y,tileC));
        // Ajout de la case dans les cases de spawn
        _spawnTiles.push_back(dynamic_cast<LandTile *>(v.back()));
    }
    else {
        v.push_back(new OceanTile(x,y));
    }
}

std::vector<std::vector<AbstractTile *>> Map::getTiles() {
    return _tiles;
}