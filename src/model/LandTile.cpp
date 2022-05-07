#include "model/LandTile.hpp"
#include "model/Map.hpp"
#include <algorithm>
#include <iostream>

LandTile::LandTile(int x, int y) : LandTile(TileType::LAND, ":", x, y) {}
LandTile::LandTile(TileType t, const char * c,int x, int y)
    : AbstractTile(t, c, x, y), _virus(VirusSeverity::NONE), _infectionTimeLeft(0), _imunityTime(0) {}

LandTile::LandTile() {}

std::vector<LandTile *> LandTile::getNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    std::vector<LandTile *> neighbours;
    if(_posX+1 < carte.size())
        addNeighbIfLandTile(carte[_posX+1][_posY], neighbours);
    if(_posX-1 >= 0)
        addNeighbIfLandTile(carte[_posX-1][_posY], neighbours);
    if(_posY+1 < carte[_posX].size())
        addNeighbIfLandTile(carte[_posX][_posY+1], neighbours);
    if(_posY-1 >= 0)
        addNeighbIfLandTile(carte[_posX][_posY-1], neighbours);
    return neighbours;
}


std::vector<LandTile *> erase(std::vector<LandTile *>& t,LandTile * l) {
    std::vector<LandTile *> toReturn;
    for(int i=0; i < t.size(); i++) {
        if(t[i] != l) {
            toReturn.push_back(t[i]);
        }
    }
    return toReturn;
}

void LandTile::addNeighbIfLandTile(AbstractTile * t, std::vector<LandTile *>& n) {
    if(t->getType() == TileType::LAND
        || t->getType() == TileType::CITY
        || t->getType() == TileType::SPAWN) {
            LandTile * lt = dynamic_cast<LandTile *>(t);
            n.push_back(lt);
        }
}

bool LandTile::isInfected() {
    return _virus != VirusSeverity::NONE;
}

VirusSeverity LandTile::getVirusSeverity() {
    return _virus;
}

void LandTile::draw(WINDOW * w,int x, int y) {
    if(isInfected()) {
        wattron(w,COLOR_PAIR(11));
        AbstractTile::draw(w,x,y);
        wattroff(w,COLOR_PAIR(11));
    }
    else {
        AbstractTile::draw(w,x,y);
    }
}

void LandTile::infect(Virus& virus) {
    _virus = VirusSeverity::LOW;
    _infectionTimeLeft = virus.getSeverity(_virus)->getLifetime();
}

void LandTile::cure(Virus& virus) {
    _virus = VirusSeverity::NONE;
    int spread = std::rand() % 101 + 1;
    if(spread > 100 - virus.getSeverity(VirusSeverity::LOW)->getImmuneChance()) {
        _imunityTime = 3;
    }
}

void LandTile::tick() {
    if(_infectionTimeLeft > 0) {
        _infectionTimeLeft--;
    }
    if(_imunityTime > 0) {
        _imunityTime--;
    }
}

void LandTile::spreadVirus(Map& map,Virus& virus) {

    std::vector<std::vector<AbstractTile *>> carte = map.getTiles();

    if(isInfected()) {

        std::vector<LandTile *> neighbours = getNeighbours(carte);
        

        for(int i=0; i < neighbours.size(); i++) {
            int spread = std::rand() % 101 + 1;
            if(!neighbours[i]->isInfected() && neighbours[i]->_imunityTime <= 0
                && spread > 100 - virus.getSeverity(_virus)->getSpreadChance()) {
                neighbours[i]->infect(virus);
                map.addInfested(neighbours[i]);
            }
        }
    }
}