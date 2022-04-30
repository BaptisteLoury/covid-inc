#ifndef VIRUS_H
#define VIRUS_H

#include <vector>
#include "AbstractBonus.hpp"
#include "Severity.hpp"

class Virus {
private:
        short _level; // niveau du virus qui le rend plus redoutable au fil des niveaux et se propage plus vite
        // std::vector<AbstractBonus &> _bonus; // potentielles améliorations pour accélérer la propagation le virus  
        Severity _lowSeverity; // le virus se déplace lentement
        Severity _mediumSeverity; // le virus se déplace rapidement
        Severity _highSeverity; // le virus se déplace très rapidement 
public:
        /**
         * @brief Construct a new Virus object
         * 
         */
        Virus(); 

        /**
         * @brief Get the Level object
         * 
         * @return short 
         */
        short getLevel();

        /**
         * @brief Set the Level object
         * 
         * @param newLevel 
         */
        void setLevel(short newLevel);

        /**
         * @brief Get the Low Severity object
         * 
         * @return Severity 
         */
        Severity getLowSeverity();

        /**
         * @brief Get the Medium Severity object
         * 
         * @return Severity 
         */
        Severity getMediumSeverity();

        /**
         * @brief Get the High Severity object
         * 
         * @return Severity 
         */
        Severity getHighSeverity();
};

#endif