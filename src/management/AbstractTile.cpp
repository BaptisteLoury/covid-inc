#include <vector>
#include "management/AbstractTile.hpp"

AbstractTile::AbstractTile() : _type(TileType::OCEAN) {}

AbstractTile::AbstractTile(TileType type) : _type(type) {}