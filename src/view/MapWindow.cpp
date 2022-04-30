#include <ncurses.h>
#include "view/MapWindow.hpp"
#include "utils/WindowUtils.hpp"

MapWindow::MapWindow() 
    : AbstractWindow(WindowType::MAP) {
    _win = subwin(stdscr, WindowUtils::MAP_HEIGHT, WindowUtils::MAP_WIDTH, WindowUtils::MAP_POSY, WindowUtils::MAP_POSX);
    }

void MapWindow::draw() {
    box(_win, ACS_VLINE, ACS_HLINE);
}