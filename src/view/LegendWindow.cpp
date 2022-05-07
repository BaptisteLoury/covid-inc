#include <ncurses.h>
#include "view/LegendWindow.hpp"
#include "utils/WindowUtils.hpp"

LegendWindow::LegendWindow() 
    : AbstractWindow(WindowType::LEGEND) {
        _win = subwin(stdscr, WindowUtils::LEGEND_HEIGHT, WindowUtils::LEGEND_WIDTH, WindowUtils::LEGEND_POSY, WindowUtils::LEGEND_POSX);
    }

void LegendWindow::draw() {
     wattron(_win,A_BOLD);

        wattron(_win,A_UNDERLINE);
            mvwprintw(_win,0,3,"LEGENDE:");
        wattroff(_win,A_UNDERLINE);
    
    
        mvwprintw(_win,0,20," \(vide\)-> l'eau");

        mvwprintw(_win,0,40," : -> la terre");
    

        mvwprintw(_win,0,60," [1-5] ->  choix spawn du virus ");

    // légende des villes
     
        wattron(_win,COLOR_PAIR(3));
                mvwprintw(_win,0,100,"[A-Z]");
        wattroff(_win,COLOR_PAIR(3));
        mvwprintw(_win,0,105," -> les villes");

        wattron(_win,COLOR_PAIR(4));
                mvwprintw(_win,0,130,"J");
        wattroff(_win,COLOR_PAIR(4));

        wattron(_win,COLOR_PAIR(4));
                mvwprintw(_win,0,133,"D");
        wattroff(_win,COLOR_PAIR(4));

         wattron(_win,COLOR_PAIR(4));
                mvwprintw(_win,0,136,"C");
        wattroff(_win,COLOR_PAIR(4));

        mvwprintw(_win,0,138," -> les villes qui correspondent entre elles");


   
    // éléments infectés 

        wattron(_win,COLOR_PAIR(11));
                mvwprintw(_win,0,190,"[A-Z][1-5][:]");
        wattroff(_win,COLOR_PAIR(11));
        mvwprintw(_win,0,203," -> les éléments infectés");
     wattron(_win,A_BOLD);

}



