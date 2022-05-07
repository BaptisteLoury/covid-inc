#include <ncurses.h>
#include "view/MapWindow.hpp"
#include "utils/WindowUtils.hpp"

MapWindow::MapWindow() 
    : AbstractWindow(WindowType::MAP) {
    _win = subwin(stdscr, WindowUtils::MAP_HEIGHT, WindowUtils::MAP_WIDTH,
                    WindowUtils::MAP_POSY, WindowUtils::MAP_POSX);
}

void MapWindow::draw() {
    box(_win, ACS_VLINE, ACS_HLINE);
    mvwprintw(_win,0,0,"");
    for(int i=0; i < _map.size(); i++) {
        for(int y=0; y < _map[i].size(); y++) {
            _map[i][y]->draw(_win,i+1,y+2);
        }
    }
}

void MapWindow::updateMap(std::vector<std::vector<AbstractTile *>> const & map) {
    _map = map;
}