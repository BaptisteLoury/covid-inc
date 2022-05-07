#ifndef ABSTRACTWINDOW_H
#define ABSTRACTWINDOW_H

#include <ncurses.h>
#include "model/Map.hpp"

enum class WindowType {MAP, LEGEND, DIALOG, STATS};

class AbstractWindow {
protected:
        WINDOW * _win;
        WindowType _type;
public :
        AbstractWindow(WindowType type);
        WINDOW * getWindow();
        virtual void draw() = 0;

        static void endGame(Map& map);
};

#endif