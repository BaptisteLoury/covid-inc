#include <vector>
#include "utils/TileUtils.hpp"
#include "model/AbstractTile.hpp"

AbstractTile::AbstractTile() : _type(TileType::OCEAN), _associatedChar(" ") {}

AbstractTile::AbstractTile(TileType type, const char * c, int x, int y) : 
    _type(type), _associatedChar(c), _posX(x), _posY(y) {}

void AbstractTile::draw() {}

TileType AbstractTile::getType() {
    return _type;
}