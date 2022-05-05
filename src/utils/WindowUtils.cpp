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
}