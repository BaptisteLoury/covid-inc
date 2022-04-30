#include <ncurses.h>
#include "view/LegendWindow.hpp"
#include "utils/WindowUtils.hpp"

LegendWindow::LegendWindow() 
    : AbstractWindow(WindowType::LEGEND) {
        _win = subwin(stdscr, WindowUtils::LEGEND_HEIGHT, WindowUtils::LEGEND_WIDTH, WindowUtils::LEGEND_POSY, WindowUtils::LEGEND_POSX);
    }

void LegendWindow::draw() {
    
}