#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <vector>
#include "view/AbstractWindow.hpp"
#include "model/AbstractTile.hpp"

class MapWindow : virtual public AbstractWindow {
private:
        std::vector<std::vector<AbstractTile *>> _map;
public:
        MapWindow();
        void draw();
        void updateMap(std::vector<std::vector<AbstractTile *>> const & map);
        void drawTiles();
};

#endif