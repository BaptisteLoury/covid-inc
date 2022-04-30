#ifndef OCEANTILE_H
#define OCEANTILE_H

#include "model/AbstractTile.hpp"

class OceanTile : public virtual AbstractTile {
public:
    OceanTile(int x, int y);
};

#endif