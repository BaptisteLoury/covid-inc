#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include "view/AbstractWindow.hpp"

class StatsWindow : virtual public AbstractWindow {
private:

public:
        StatsWindow();
        void draw();
};

#endif