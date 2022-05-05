#include "model/SpawnTile.hpp"

SpawnTile::SpawnTile(int x, int y, const char * c) :  AbstractTile(TileType::SPAWN, c, x, y) {
    _virus = VirusSeverity::NONE;
}

void SpawnTile::draw(WINDOW * w,int x, int y) {
    wattron(w,A_BOLD | A_UNDERLINE);
    LandTile::draw(w,x,y);
    wattroff(w,A_BOLD | A_UNDERLINE);
}