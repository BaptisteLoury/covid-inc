#ifndef VIRUSCONTROLLER_H
#define VIRUSCONTROLLER_H

#include "model/Map.hpp"
#include "model/Virus.hpp"
#include "view/DialogWindow.hpp"

class VirusController {
private:
    static void checkSpawns(Map& map);
    static void tickVirus(Map& map,Virus& virus);
public:
    static void spreadVirus(Map& map,Virus * virus,DialogWindow* w);
};

#endif