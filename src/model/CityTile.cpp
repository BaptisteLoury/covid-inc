#include "model/CityTile.hpp"
#include "utils/TileUtils.hpp"
#include <iostream>
#include "model/Severity.hpp"
#include <fstream>

std::vector<std::vector<LandTile *>> CityTile::ASSO = {};

CityTile::CityTile(int x, int y, const char * c) :  AbstractTile(TileType::CITY, c, x, y) {
    _virus = VirusSeverity::NONE;
    _infectionTimeLeft = 0;
    _imunityTime = 0;
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
    if(ASSO.size() == 0) {
        for(int i=0; i < 5; i++) {
            ASSO.push_back({});
        }
    }
    ASSO[_cityGroup].push_back(this);
}

std::vector<LandTile *> CityTile::getNeighbours(std::vector<std::vector<AbstractTile *>> &carte) {
    std::vector<LandTile *> relatedCities = LandTile::getNeighbours(carte);
    std::vector<LandTile *> a = getCityAsso();
    relatedCities.insert(relatedCities.end(), a.begin(), a.end());

    std::ofstream file;
    file.open("log.err", std::ios::app);
    file << relatedCities.size() << std::endl;
    file.close();

    return relatedCities;
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

std::vector<LandTile *> CityTile::getCityAsso() {
    std::vector<LandTile *> asso;
    for(int i=0; i < ASSO[_cityGroup].size(); i++) {
        if(ASSO[_cityGroup][i] != this) {
            asso.push_back(ASSO[_cityGroup][i]);
        }
    }
    return asso;
}