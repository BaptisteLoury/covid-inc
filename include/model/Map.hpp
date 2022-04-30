#ifndef MAP_H
#define MAP_H

#include <vector>
#include "AbstractTile.hpp"
#include "LandTile.hpp"
#include "OceanTile.hpp"

class Map {
private:
        int _nbLandTiles;
        std::vector<std::vector<AbstractTile *>> _tiles;
        std::vector<LandTile *> _infestedTiles;
        std::vector<LandTile *> _spawnTiles;
public:
        Map();
        Map(std::vector<std::string> charMap);
        std::vector<std::vector<AbstractTile *>> getTiles();
        std::vector<LandTile *> getInfestedTiles();
        std::vector<LandTile *> getSpawnTiles();
        
        int getNbLandTiles();
        void addTile(int x, int y, char c, std::vector<AbstractTile *>& v);
};

#endif