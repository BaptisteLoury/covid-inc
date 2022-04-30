#ifndef VIRUS_H
#define VIRUS_H

#include <vector>
#include "AbstractBonus.hpp"
#include "Severity.hpp"

class Virus {
private:
        short _level; // niveau du virus qui le rend plus redoutable au fil des niveaux et se propage plus vite
        std::vector<AbstractBonus &> _bonus; // potentielle amélioration pour accélérer le virus  
        Severity _lowSeverity; // le virus se déplace lentement
        Severity _mediumSeverity; // le virus se déplace rapidement
        Severity _highSeverity; // le virus se déplace très rapidement 
public:
        Virus(); 

        
        short getLevel();
        void setLevel();
    virtual void draw();         

};

#endif