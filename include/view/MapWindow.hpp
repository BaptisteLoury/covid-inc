#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <vector>
#include "view/AbstractWindow.hpp"
#include "model/AbstractTile.hpp"

class MapWindow : virtual public AbstractWindow {
private:
        std::vector<std::vector<AbstractTile *>> _map;

        void initColors();
public:
        MapWindow();
        void draw();
        void updateMap(std::vector<std::vector<AbstractTile *>> map);
        void drawTiles();
};

#endif