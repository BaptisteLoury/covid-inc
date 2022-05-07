#include "controller/VirusController.hpp"
#include "model/Map.hpp"
#include "model/LevelUpDialog.hpp"
#include <algorithm>

void VirusController::spreadVirus(Map& map,Virus * virus,DialogWindow * w) {

    if(virus->getLivingTime().diffWithCurrent(virus->getLastProke()) >= 1000) {


        if(virus->addExp(map.countInfested())) {
            w->setDialog(new LevelUpDialog(virus));
        }

        virus->setLastProke();
        tickVirus(map,*virus);
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


void VirusController::tickVirus(Map& map,Virus& virus) {

    std::vector<LandTile *> infected = map.getInfestedTiles();
    std::vector<std::vector<AbstractTile *>> tiles = map.getTiles();

    for(int i=0; i < tiles.size();i++) {
        for(int y=0; y < tiles[i].size(); y++) {
            if(tiles[i][y]->getType() != TileType::OCEAN) {
                dynamic_cast<LandTile *>(tiles[i][y])->tick();
            }
        }
    }

    for(int i=0; i < infected.size(); i++) {

        if(infected[i]->getInfectionTimeLeft() < 1) {
            infected[i]->cure(virus);
            map.removeInfested(infected[i]);
        }
        else {

            std::vector<std::vector<AbstractTile *>> carte = map.getTiles();
            infected[i]->spreadVirus(map,virus);
        }
    }
}
