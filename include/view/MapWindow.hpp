#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <vector>
#include "view/AbstractWindow.hpp"

class MapWindow : virtual public AbstractWindow {
private:
        std::vector<std::vector<const char *>> _charMap;
public:
        MapWindow();
        void draw();
        void updateMap(std::vector<std::vector<const char *>> charMap);
        void drawTiles();
};

#endif