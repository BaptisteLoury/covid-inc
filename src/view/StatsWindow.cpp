#include <ncurses.h>
#include "view/StatsWindow.hpp"
#include "utils/WindowUtils.hpp"
#include <iostream>

StatsWindow::StatsWindow(Virus& virus) 
    : AbstractWindow(WindowType::STATS), _virus(virus) {
        _win = subwin(stdscr, WindowUtils::STATS_HEIGHT, WindowUtils::STATS_WIDTH, WindowUtils::STATS_POSY, WindowUtils::STATS_POSX);
    }

void StatsWindow::draw() {
    box(_win, ACS_VLINE, ACS_HLINE);
    wattron(_win,A_BOLD);
    mvwprintw(_win, 1, 1, "%s", timeDecorator().c_str());
    wattroff(_win,A_BOLD);
}

std::string StatsWindow::timeDecorator() {
    int time = _virus.getLivingTime().time();
    int minutes = time / 60000;
    int secondes = (time % 60000) / 1000;
    std::string s_decorator = minutes > 9 ? "" : "0";
    s_decorator += std::to_string(minutes) + ":" + std::to_string(secondes / 10) + std::to_string(secondes % 10);
    return s_decorator;
}