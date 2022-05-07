#include <vector>
#include <ncurses.h>
#include "utils/TileUtils.hpp"
#include "model/AbstractTile.hpp"

AbstractTile::AbstractTile() : _type(TileType::OCEAN), _associatedChar(" ") {}

AbstractTile::AbstractTile(TileType type, const char * c, int x, int y) : 
    _type(type), _associatedChar(c), _posX(x), _posY(y) {}

void AbstractTile::draw(WINDOW * w, int x, int y) {
    mvwprintw(w,x,y,_associatedChar);
}

TileType AbstractTile::getType() {
    return _type;
}

const char * AbstractTile::getChar() {
    return _associatedChar;
}

void AbstractTile::setChar(const char * c) {
    _associatedChar = c;
}

int AbstractTile::getX() {
    return _posX;
}

int AbstractTile::getY() {
    return _posY;
}