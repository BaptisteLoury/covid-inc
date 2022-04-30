#include <ncurses.h>
#include "view/LegendWindow.hpp"
#include "utils/WindowUtils.hpp"

LegendWindow::LegendWindow() 
    : AbstractWindow(WindowUtils::LEGEND_HEIGHT, WindowUtils::LEGEND_WIDTH, WindowUtils::LEGEND_POSY, WindowUtils::LEGEND_POSX, WindowType::LEGEND) {}

void LegendWindow::draw() {
    
}