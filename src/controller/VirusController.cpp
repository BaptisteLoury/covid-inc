#include "controller/VirusController.hpp"
#include "model/Map.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>

void VirusController::spreadVirus(Map& map,Virus& virus) {

    if(virus.getLivingTime().diffWithCurrent(virus.getLastProke()) >= 1000) {

        virus.setLastProke();
        tickVirus(map);
        checkSpawns(map);
    }
}

void VirusController::checkSpawns(Map& map) {

    std::vector<SpawnTile *> spawns = map.getSpawnTiles();
    std::vector<LandTile *> infected = map.getInfestedTiles();

    for(int i=0; i < spawns.size(); i++) {

        if(std::find(infected.begin(), infected.end(), spawns[i]) == infected.end() && spawns[i]->isInfected()) {

            map.addInfested(spawns[i]);

        }
    }
}


void VirusController::tickVirus(Map& map) {

    std::vector<LandTile *> infected = map.getInfestedTiles();

    for(int i=0; i < infected.size(); i++) {

        infected[i]->tick();

        if(infected[i]->getInfectionTimeLeft() < 1) {
            infected[i]->cure();
            map.removeInfested(infected[i]);
        }
        else {

            std::vector<std::vector<AbstractTile *>> carte = map.getTiles();
            infected[i]->spreadVirus(map);
        }
    }
}
