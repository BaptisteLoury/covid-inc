#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include "view/AbstractWindow.hpp"
#include "model/Virus.hpp"
#include <string>
#include "model/Map.hpp"

class StatsWindow : virtual public AbstractWindow {
private:
        Virus _virus;
        Map _map;

        std::string timeDecorator();
public:
        StatsWindow(Virus &virus, Map &map);
        void draw();
};

#endif