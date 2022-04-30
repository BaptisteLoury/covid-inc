#ifndef WINDOWUTILS_H
#define WINDOWUTILS_H

#include <ncurses.h>

class WindowUtils {
public:
    static const int MAP_WIDTH;
    static const int MAP_HEIGHT;
    static const int MAP_POSX;
    static const int MAP_POSY;

    static const int LEGEND_WIDTH;
    static const int LEGEND_HEIGHT;
    static const int LEGEND_POSX;
    static const int LEGEND_POSY;

    static const int DIALOG_WIDTH;
    static const int DIALOG_HEIGHT;
    static const int DIALOG_POSX;
    static const int DIALOG_POSY;

    static const int STATS_WIDTH;
    static const int STATS_HEIGHT;
    static const int STATS_POSX;
    static const int STATS_POSY;
};

const int WindowUtils::MAP_WIDTH = COLS;
const int WindowUtils::MAP_HEIGHT = 46;
const int WindowUtils::MAP_POSX = 0;
const int WindowUtils::MAP_POSY = 0;

const int WindowUtils::LEGEND_WIDTH = COLS;
const int WindowUtils::LEGEND_HEIGHT = 1;
const int WindowUtils::LEGEND_POSX = 0;
const int WindowUtils::LEGEND_POSY = 46;

const int WindowUtils::DIALOG_WIDTH = COLS/2;
const int WindowUtils::DIALOG_HEIGHT = LINES - 47;
const int WindowUtils::DIALOG_POSX = 0;
const int WindowUtils::DIALOG_POSY = 47;

const int WindowUtils::STATS_WIDTH = COLS/2;
const int WindowUtils::STATS_HEIGHT = LINES - 47;
const int WindowUtils::STATS_POSX = COLS/2;
const int WindowUtils::STATS_POSY = 47;

//         _map = subwin(stdscr, 46, COLS, 0, 0);
//         _legend = subwin(stdscr, 1, COLS, 46, 0);
//         _dialog = subwin(stdscr, LINES - 47, COLS/2, 47, 0);
//         _stats = subwin(stdscr, LINES - 47, COLS/2, 47, COLS/2);

#endif