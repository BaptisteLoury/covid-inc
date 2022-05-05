#include <ncurses.h>
#include <iostream>
#include "../include/utils/Timer.hpp"

int main() {
    initscr();
    start_color();
    use_default_colors();

    Timer timer;
    timer.Start();
    std::chrono::_V2::steady_clock::duration lastLoop = timer.GetElapsed();

    int i = 0;

    while(1) {
        if(timer.diffWithCurrent(lastLoop) > 100) {
            lastLoop = timer.GetElapsed();
            clear();
            box(stdscr, ACS_VLINE, ACS_HLINE);
        mvprintw(2,2,"%d",i);
            refresh();
        i++;
        }
    }

    endwin();
}  