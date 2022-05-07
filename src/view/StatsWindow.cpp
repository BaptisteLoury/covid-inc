#include <ncurses.h>
#include "view/StatsWindow.hpp"
#include "utils/WindowUtils.hpp"
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
        
        mvwprintw(_win, 3, 1, " Total de cases infectées %d", _map->countInfested());

        mvwprintw(_win, 5, 1, " Taux de cases infectées %.2f%c", _map->percentageInfested(),'%');

        box(_win, ACS_VLINE, ACS_HLINE);
   
        mvwprintw(_win, 10, 1, "Temps passé : %s", timeDecorator().c_str());

        mvwprintw(_win, 11, 1, "Level %hd", _virus->getLevel());
        if(_virus->getLevel() < 10)
            mvwprintw(_win, 11, 15, "Exp : %d/%d", _virus->getExp(),_virus->getExpCap());
        else
            mvwprintw(_win, 11, 15, "MAX");

        mvwprintw(_win, 13, 1, "Chance de propagation : %.2f%c", _virus->getSeverity(VirusSeverity::LOW)->getSpreadChance(),'%');
        mvwprintw(_win, 14, 1, "Durée de vie : %.2fs", _virus->getSeverity(VirusSeverity::LOW)->getLifetime());
        mvwprintw(_win, 15, 1, "Risque d'immunité : %.2f%c", _virus->getSeverity(VirusSeverity::LOW)->getImmuneChance(),'%');

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
