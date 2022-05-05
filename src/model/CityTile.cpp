#include "model/CityTile.hpp"
#include "utils/TileUtils.hpp"
#include <iostream>
#include "model/Severity.hpp"

CityTile::CityTile(int x, int y, const char * c) :  AbstractTile(TileType::CITY, c, x, y) {
    _virus = VirusSeverity::NONE;
    bool found = false;
    int i = 0;
    while(!found && i < TileUtils::CITY_ASSO.size()) {
            int y = 0;
            while(!found && y < TileUtils::CITY_ASSO[i].size()) {
                    if(TileUtils::CITY_ASSO[i][y][0] == _associatedChar[0]) {
                            found = true;
                            _cityGroup = i;
                    }
                    y++;
            }
            i++;
    }
    if(!found) {
            _cityGroup = i-1;
    }

}

std::vector<LandTile *> CityTile::getNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    return LandTile::getNeighbours(carte);
}

std::vector<LandTile *> CityTile::getInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    return LandTile::getInfectedNeighbours(carte);
}

std::vector<LandTile *> CityTile::getNotInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    return LandTile::getNotInfectedNeighbours(carte);
}

void CityTile::draw(WINDOW * w,int x, int y) {
    wattron(w,A_BOLD | A_UNDERLINE);
    // LandTile::draw(w,x,y);
    if(isInfected()) {
        wattron(w,COLOR_PAIR(_cityGroup + 6));
        AbstractTile::draw(w,x,y);
        wattroff(w,COLOR_PAIR(_cityGroup + 6));
    }
    else {
        wattron(w,COLOR_PAIR(_cityGroup + 1));
        AbstractTile::draw(w,x,y);
        wattroff(w,COLOR_PAIR(_cityGroup + 1));
    }
    wattroff(w,A_BOLD | A_UNDERLINE);
}