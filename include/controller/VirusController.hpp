#ifndef VIRUSCONTROLLER_H
#define VIRUSCONTROLLER_H

#include "model/Map.hpp"
#include "model/Virus.hpp"

class VirusController {
public:
    static void spreadVirus(Map& map,Virus& virus);
};

#endif