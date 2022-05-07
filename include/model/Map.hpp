#ifndef MAP_H
#define MAP_H

#include <vector>
#include "AbstractTile.hpp"
#include "LandTile.hpp"
#include "OceanTile.hpp"
#include "CityTile.hpp"
#include "SpawnTile.hpp"

class Map {
private:
        bool _hasGameBegun;
        // Toutes les cases
        std::vector<std::vector<AbstractTile *>> _tiles;

        // Permet d'éviter d'avoir à parcourir toutes les cases
        std::vector<LandTile *> _infestedTiles;
        std::vector<SpawnTile *> _spawnTiles;
public:
        Map();
        Map(std::vector<std::string> charMap);
        std::vector<std::vector<AbstractTile *>> getTiles();
        std::vector<LandTile *> getInfestedTiles();
        std::vector<SpawnTile *> getSpawnTiles();
        
        int getNbLandTiles();
        void addTile(int x, int y, char c, std::vector<AbstractTile *>& v);
        void addInfested(LandTile * tile);
        
        void removeInfested(LandTile * tile);
        int countInfested();
        int countLand();
        float percentageInfested();
        bool hasGameBegun();
};

#endif