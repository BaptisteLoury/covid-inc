#include <ncurses.h>
#include <curses.h>
#include <vector>
#include <iostream>
#include "core/Application.hpp"
#include "utils/MapUtils.hpp"

Application::Application()  {
}

void Application::run(){
    
    windowsSetup();

    MapUtils utils;
    vector<string> mapT = utils.getMapTable();
    

    while(1) {
        clear();
        drawBorders();
        mvwprintw(_map,0,0,"");
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

void Application::windowsSetup() {
    initscr();
    start_color();
    use_default_colors();
    init_color(COLOR_BLACK, 0, 0, 0);

    init_pair(1,COLOR_RED,COLOR_BLACK);

    
    
    // _map = subwin(stdscr, LINES * 3/4,COLS,0,0);


    // _menu = subwin(stdscr, LINES * 1/4,COLS,0,0);

    initWindows();

    wbkgd(_map, COLOR_PAIR(1));
}

void Application::initWindows() {
        _map = subwin(stdscr, 46, COLS, 0, 0);
        _legend = subwin(stdscr, 1, COLS, 46, 0);
        _dialog = subwin(stdscr, LINES - 47, COLS/2, 47, 0);
        _stats = subwin(stdscr, LINES - 47, COLS/2, 47, COLS/2);
        drawBorders();
}

void Application::drawBorders() {
        box(_map, ACS_VLINE, ACS_HLINE);
        box(_dialog, ACS_VLINE, ACS_HLINE);
        box(_stats, ACS_VLINE, ACS_HLINE);


}
