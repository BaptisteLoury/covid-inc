#ifndef VIRUS_H
#define VIRUS_H

#include <vector>
#include "AbstractBonus.hpp"
#include "Severity.hpp"

class Virus {
private:
        short _level;
        std::vector<AbstractBonus &> _bonus;
        Severity _lowSeverity;
        Severity _mediumSeverity;
        Severity _highSeverity;
public:
};

#endif