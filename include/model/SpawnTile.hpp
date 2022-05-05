#ifndef SPAWNTILE_H
#define SPAWNTILE_H

#include <vector>
#include "LandTile.hpp"

class SpawnTile : virtual public LandTile {
protected:
public:
    SpawnTile(int x, int y, const char * c);
    void draw(WINDOW * w,int x, int y);
};

#endif