#include <ncurses.h>

int main() {
    initscr();              // Initialise la structure WINDOW et autres paramètres
    
    start_color();

    init_pair(1,COLOR_RED,COLOR_WHITE);

    attron(COLOR_PAIR(1));
    mvaddch(0,0,'a');
    attroff(COLOR_PAIR(1));


    refresh();
    getch();
    endwin();  
}  