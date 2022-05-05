#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include "view/AbstractWindow.hpp"
#include "model/Virus.hpp"
#include <string>

class StatsWindow : virtual public AbstractWindow {
private:
        Virus _virus;

        std::string timeDecorator();
public:
        StatsWindow(Virus &virus);
        void draw();
};

#endif