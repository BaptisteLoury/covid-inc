#include <ncurses.h>
#include "view/StatsWindow.hpp"
#include "utils/WindowUtils.hpp"

StatsWindow::StatsWindow() 
    : AbstractWindow(WindowUtils::STATS_HEIGHT, WindowUtils::STATS_WIDTH, WindowUtils::STATS_POSY, WindowUtils::STATS_POSX, WindowType::STATS) {}

void StatsWindow::draw() {
    box(_win, ACS_VLINE, ACS_HLINE);
}