#ifndef WINDOWUTILS_H
#define WINDOWUTILS_H

#include <ncurses.h>

class WindowUtils {
public:
    static void initConsts();

    static int MAP_WIDTH;
    static int MAP_HEIGHT;
    static int MAP_POSX;
    static int MAP_POSY;

    static int LEGEND_WIDTH;
    static int LEGEND_HEIGHT;
    static int LEGEND_POSX;
    static int LEGEND_POSY;

    static int DIALOG_WIDTH;
    static int DIALOG_HEIGHT;
    static int DIALOG_POSX;
    static int DIALOG_POSY;

    static int STATS_WIDTH;
    static int STATS_HEIGHT;
    static int STATS_POSX;
    static int STATS_POSY;
};


#endif