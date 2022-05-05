#include <ncurses.h>
#include "view/MapWindow.hpp"
#include "utils/WindowUtils.hpp"

MapWindow::MapWindow() 
    : AbstractWindow(WindowType::MAP) {
    _win = subwin(stdscr, WindowUtils::MAP_HEIGHT, WindowUtils::MAP_WIDTH,
                    WindowUtils::MAP_POSY, WindowUtils::MAP_POSX);
    initColors();
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

void MapWindow::updateMap(std::vector<std::vector<AbstractTile *>> map) {
    _map = map;
}

void MapWindow::initColors() {
    init_pair(0, COLOR_RED, COLOR_BLACK);
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_CYAN);
    init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(5, COLOR_BLACK, COLOR_YELLOW);
    init_pair(6, COLOR_RED, COLOR_BLUE);
    init_pair(7, COLOR_RED, COLOR_GREEN);
    init_pair(8, COLOR_RED, COLOR_CYAN);
    init_pair(9, COLOR_RED, COLOR_MAGENTA);
    init_pair(10, COLOR_RED, COLOR_YELLOW);
}