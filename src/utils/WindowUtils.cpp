#include "utils/WindowUtils.hpp"
#include <ncurses.h>

int WindowUtils::MAP_WIDTH = COLS;
int WindowUtils::MAP_HEIGHT = 46;
int WindowUtils::MAP_POSX = 0;
int WindowUtils::MAP_POSY = 0;

int WindowUtils::LEGEND_WIDTH = COLS;
int WindowUtils::LEGEND_HEIGHT = 1;
int WindowUtils::LEGEND_POSX = 0;
int WindowUtils::LEGEND_POSY = 46;

int WindowUtils::DIALOG_WIDTH = COLS/2;
int WindowUtils::DIALOG_HEIGHT = LINES - 47;
int WindowUtils::DIALOG_POSX = 0;
int WindowUtils::DIALOG_POSY = 47;

int WindowUtils::STATS_WIDTH = COLS/2;
int WindowUtils::STATS_HEIGHT = LINES - 47;
int WindowUtils::STATS_POSX = COLS/2;
int WindowUtils::STATS_POSY = 47;


void WindowUtils::initConsts() {
    MAP_WIDTH = COLS;

    LEGEND_WIDTH = COLS;

    DIALOG_WIDTH = COLS/2;
    DIALOG_HEIGHT = LINES - 47;

    STATS_WIDTH = COLS/2;
    STATS_HEIGHT = LINES - 47;
    STATS_POSX = COLS/2;

    init_pair(11, COLOR_RED, -1); // paire 0 indéfinissable
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_CYAN);
    init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(5, COLOR_BLACK, COLOR_YELLOW);
    init_pair(6, COLOR_RED, COLOR_BLUE);
    init_pair(7, COLOR_RED, COLOR_GREEN);
    init_pair(8, COLOR_RED, COLOR_CYAN);
    init_pair(9, COLOR_RED, COLOR_MAGENTA);
    init_pair(10, COLOR_RED, COLOR_YELLOW);
}