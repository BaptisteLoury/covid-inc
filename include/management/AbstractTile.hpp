#include <vector>

enum TileType {OCEAN,LAND,CITY};

class AbstractTile {

private:
    TileType _type;
public:
    AbstractTile();
    AbstractTile(TileType type);
    TileType getType();
};