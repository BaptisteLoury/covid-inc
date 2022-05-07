#ifndef CITYTILE_H
#define CITYTILE_H

#include <vector>
#include "LandTile.hpp"

class CityTile : virtual public LandTile {
private:
    int _cityGroup;

public:
    CityTile(int x, int y, const char * c);
    std::vector<LandTile *> getNeighbours(std::vector<std::vector<AbstractTile *>> &carte);
    void draw(WINDOW * w,int x, int y);
    std::vector<LandTile *> getCityAsso();

    static std::vector<std::vector<LandTile *>> ASSO;
};

#endif