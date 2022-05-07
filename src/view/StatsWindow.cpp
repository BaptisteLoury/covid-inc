#include <ncurses.h>
#include "view/StatsWindow.hpp"
#include "utils/WindowUtils.hpp"
#include <iostream>
#include "model/Map.hpp"

StatsWindow::StatsWindow(Virus * virus, Map * map) 
    : AbstractWindow(WindowType::STATS), _virus(virus), _map(map) {
        _win = subwin(stdscr, WindowUtils::STATS_HEIGHT, WindowUtils::STATS_WIDTH, WindowUtils::STATS_POSY, WindowUtils::STATS_POSX);
    
    }

void StatsWindow::draw() {
     wattron(_win,A_BOLD);
        wattron(_win,A_UNDERLINE);
            mvwprintw(_win, 1, 50, "VISUALISATION");
        wattroff(_win,A_UNDERLINE);
        
        mvwprintw(_win, 5, 1, " Total de cases infectées %d", _map->countInfested());

        box(_win, ACS_VLINE, ACS_HLINE);
   
        mvwprintw(_win, 10, 1, "%s", timeDecorator().c_str());
    wattroff(_win,A_BOLD);



}

std::string StatsWindow::timeDecorator() {
    int time = _virus->getLivingTime().time();
    int minutes = time / 60000;
    int secondes = (time % 60000) / 1000;
    std::string s_decorator = minutes > 9 ? "" : "0";
    s_decorator += std::to_string(minutes) + ":" + std::to_string(secondes / 10) + std::to_string(secondes % 10);
    return s_decorator;
}