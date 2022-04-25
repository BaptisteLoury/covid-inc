#include <ncurses.h>
#include <vector>
#include <iostream>
#include "core/Application.hpp"
#include "utils/MapUtils.hpp"

Application::Application()  {
}

void Application::run(){
    initscr();              // Initialise la structure WINDOW et autres paramètres
    
    _map = subwin(stdscr, LINES * 3/4,COLS,0,0);

    _menu = subwin(stdscr, LINES * 1/4,COLS,0,0);

    MapUtils utils;
    vector<string> mapT = utils.getMapTable();

    

    while(1) {
        clear();
        box(_map,ACS_VLINE,ACS_HLINE);
        mvwprintw(_map,2,2,"");
        for(int i=0; i < mapT.size(); i++) {
            int x, y; // colonne et ligne
            getyx(_map,y,x);
            mvwprintw(_map,y+1,2,mapT[i].c_str());
        }
        refresh();
        if(getch() != 410)
            break;
    }
    
    endwin();               // Restaure les paramètres par défaut du terminal
}