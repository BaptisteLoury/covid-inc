#ifndef ABSTRACTTILE_H
#define ABSTRACTTILE_H

#include <vector>
#include <string>

enum class TileType {OCEAN,LAND,CITY,SPAWN};

class AbstractTile {

protected:
    TileType _type;
    const char * _associatedChar;
    int _posX;
    int _posY;
public:
    AbstractTile();
    AbstractTile(TileType type, const char * c, int x, int y);
    TileType getType();
    int getX();
    int getY();
    virtual void draw();
};

#endif