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
    _hasGameBegun = false;
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
        _spawnTiles.push_back(dynamic_cast<SpawnTile *>(v.back()));
    }
    else {
        v.push_back(new OceanTile(x,y));
    }
}

std::vector<std::vector<AbstractTile *>> Map::getTiles() {
    return _tiles;
}

std::vector<SpawnTile *> Map::getSpawnTiles() {
    return _spawnTiles;
}

std::vector<LandTile *> Map::getInfestedTiles() {
    return _infestedTiles;
}

void Map::addInfested(LandTile * tile) {
    _hasGameBegun = true;
    _infestedTiles.push_back(tile);
}

int Map::countInfested() {
    int count = 0;
    for(int i=0; i < _tiles.size(); i++) {
        for(int y=0; y < _tiles[i].size(); y++) {
            if(_tiles[i][y]->getType() != TileType::OCEAN) {
                if(dynamic_cast<LandTile *>(_tiles[i][y])->isInfected()) {
                    count++;
                }
            }
        }
    }
    return count;
}

void Map::removeInfested(LandTile * tile) {
    bool found = false;
    int i = 0;
    while(i < _infestedTiles.size() && !found) {
        if(_infestedTiles[i] == tile) {
            found = true;
        }
        else {
            i++;
        }
    }
    while(i < _infestedTiles.size() - 1) {
        _infestedTiles[i] = _infestedTiles[i+1];
        i++;
    }
    _infestedTiles.pop_back();
}    

float Map::percentageInfested(){
    int nbIndestedTiles= countInfested();
    int nbTotalTiles= countLand();
    float percentage = ((float)nbIndestedTiles/(float)nbTotalTiles)*100;
    return percentage;
}

int Map::countLand() {
    int count = 0;
    for(int i=0; i < _tiles.size(); i++) {
        for(int y=0; y < _tiles[i].size(); y++) {
            if(TileType::OCEAN != _tiles[i][y]->getType()) {
                count++;
            }
        }
    }
    return count;
}

bool Map::hasGameBegun() {
    return _hasGameBegun;
}