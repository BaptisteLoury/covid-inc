#include <vector>
#include <string>

enum TileType {OCEAN,LAND,CITY};

class AbstractTile {

private:
    TileType _type;
    const char * _associatedChar;
public:
    AbstractTile();
    AbstractTile(TileType type, const std::string& c);
    TileType getType();
};