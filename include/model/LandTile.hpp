#ifndef LANDTILE_H
#define LANDTILE_H

#include <vector>
#include "AbstractTile.hpp"
#include "Severity.hpp"

class LandTile : virtual public AbstractTile {
protected:
        VirusSeverity _virus;

        void addNeighbIfLandTile(AbstractTile * t, std::vector<LandTile *>& n);
public:
        LandTile(int x, int y);
        bool isInfected();
        VirusSeverity getVirusSeverity();
        virtual std::vector<LandTile *> getNeighbours(std::vector<std::vector<AbstractTile *>> &carte);
        virtual std::vector<LandTile *> getInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte);
        virtual std::vector<LandTile *> getNotInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte);
};

#endif