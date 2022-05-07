#include "model/LandTile.hpp"
#include "model/Map.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>

LandTile::LandTile(int x, int y) : LandTile(TileType::LAND, ":", x, y) {}
LandTile::LandTile(TileType t, const char * c,int x, int y)
    : AbstractTile(t, c, x, y), _virus(VirusSeverity::NONE), _infectionTimeLeft(0) {}

LandTile::LandTile() {}

std::vector<LandTile *> LandTile::getNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    std::vector<LandTile *> neighbours;
    addNeighbIfLandTile(carte[_posX+1][_posY], neighbours);
    addNeighbIfLandTile(carte[_posX-1][_posY], neighbours);
    addNeighbIfLandTile(carte[_posX][_posY+1], neighbours);
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

void LandTile::infect() {
    _virus = VirusSeverity::LOW;
    _infectionTimeLeft = 10;
}

void LandTile::cure() {
    _virus = VirusSeverity::NONE;
}

void LandTile::tick() {
    _infectionTimeLeft--;
}

void LandTile::spreadVirus(Map& map) {

    std::vector<std::vector<AbstractTile *>> carte = map.getTiles();

    if(isInfected()) {

        std::vector<LandTile *> neighbours = getNeighbours(carte);

                    std::ofstream file;
    file.open("log.err", std::ios::app);
    file<< "pre:" << _posX << ":" << _posY << ":" << map.getInfestedTiles().size() << "\n";
        

        for(int i=0; i < neighbours.size(); i++) {
            if(!neighbours[i]->isInfected()) {
                neighbours[i]->infect();
                map.addInfested(neighbours[i]);
        file<< "during:" << neighbours[i]->getX() << ":" << neighbours[i]->getY() << "\n";
            }
        }
    file<< "post:" << _posX << ":" << _posY << ":" << map.getInfestedTiles().size() << "\n";
    file<< "count:"  << map.countInfested() << "\n\n";
    file.close();
    }
}