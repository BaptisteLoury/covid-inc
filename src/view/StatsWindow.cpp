#include <ncurses.h>
#include "view/StatsWindow.hpp"
#include "utils/WindowUtils.hpp"

StatsWindow::StatsWindow() 
    : AbstractWindow(WindowType::STATS) {
        _win = subwin(stdscr, WindowUtils::STATS_HEIGHT, WindowUtils::STATS_WIDTH, WindowUtils::STATS_POSY, WindowUtils::STATS_POSX);
    }

void StatsWindow::draw() {
    box(_win, ACS_VLINE, ACS_HLINE);
}