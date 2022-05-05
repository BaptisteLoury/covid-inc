#include "model/LandTile.hpp"
#include <algorithm>

LandTile::LandTile(int x, int y) : LandTile(TileType::LAND, ":", x, y) {}
LandTile::LandTile(TileType t, const char * c,int x, int y)
    : AbstractTile(t, c, x, y), _virus(VirusSeverity::NONE) {}

LandTile::LandTile() {}

std::vector<LandTile *> LandTile::getNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    std::vector<LandTile *> neighbours;
    addNeighbIfLandTile(carte[_posX+1][_posY], neighbours);
    addNeighbIfLandTile(carte[_posX-1][_posY], neighbours);
    addNeighbIfLandTile(carte[_posX][_posY+1], neighbours);
    addNeighbIfLandTile(carte[_posX][_posY-1], neighbours);
    return neighbours;
}

std::vector<LandTile *> LandTile::getInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    std::vector<LandTile *> infected = getNeighbours(carte);
    for(int i=0; i < infected.size(); i++) {
        if(!infected[i]->isInfected())
            infected.erase(infected.begin() + i);
    }
    return infected;
}

std::vector<LandTile *> LandTile::getNotInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    std::vector<LandTile *> infected = getNeighbours(carte);
    for(int i=0; i < infected.size(); i++) {
        if(infected[i]->isInfected())
            infected.erase(infected.begin() + i);
    }
    return infected;
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
        attron(COLOR_PAIR(0));
        AbstractTile::draw(w,x,y);
        attroff(COLOR_PAIR(0));
    }
    else {
        AbstractTile::draw(w,x,y);
    }
}