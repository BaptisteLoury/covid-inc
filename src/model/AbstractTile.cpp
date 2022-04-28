#include <vector>
#include "utils/TileUtils.hpp"
#include "model/AbstractTile.hpp"

AbstractTile::AbstractTile() : _type(TileType::OCEAN), _associatedChar(TileUtils::initChar(" ")) {}

AbstractTile::AbstractTile(TileType type, const std::string& c) : _type(type), _associatedChar(TileUtils::initChar(c)) {}