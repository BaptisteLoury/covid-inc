#ifndef SEVERITY_H
#define SEVERITY_H

enum class VirusSeverity{
        NONE, LOW, MEDIUM, HIGH
};

class Severity {
protected:
        // const float _initSpreadChance;
        // const float _initLifetime;
        // const float _initEvolveChance;
        // const int _initScorePerSec;
        float _spreadChance;
        float _lifetime;
        float _evolveChance;
        int _scorePerSec;
        VirusSeverity _severityType;
public:
        /**
         * @brief Construct a new Severity object: Il prend en paramètre le type de sévérité qui ajustera les caractéristiques
         * 
         * @param severityType 
         */
        Severity(VirusSeverity severityType); 

        /**
         * @brief Get the Init Spread Chance object
         * 
         * @return float 
         */
        float getInitSpreadChance(); 

        /**
         * @brief Get the Init Lifetime object
         * 
         * @return float 
         */
        float getInitLifetime();

        /**
         * @brief Get the Init Evolve Chance object
         * 
         * @return float 
         */
        float getInitEvolveChance();

        /**
         * @brief Get the Init Score Per Sec object
         * 
         * @return int 
         */
        int getInitScorePerSec();

        
        /**
         * @brief Get the Spread Chance object
         * 
         * @return float 
         */
        float getSpreadChance();


       /**
        * @brief Set the Spread Chance object
        * 
        * @param newSpreadChance 
        */
        void setSpreadChance(float newSpreadChance);


        /**
         * @brief Get the Lifetime object
         * 
         * @return float 
         */
        float getLifetime();

        /**
         * @brief Set the Lifetime object
         * 
         * @param newLifeTime 
         */
        void setLifetime(float newLifeTime);

        /**
         * @brief Get the Evolve Chance object
         * 
         * @return float 
         */
        float getEvolveChance();

       /**
        * @brief Set the Evolve Chance object
        * 
        * @param newEvolveChance 
        */
        void setEvolveChance(float newEvolveChance);

        /**
         * @brief Get the Score Per Sec object
         * 
         * @return int 
         */
        int getScorePerSec();

        /**
         * @brief Set the Score Per Sec object
         * 
         * @param newScore 
         */
        void setScorePerSec(int newScore);


        /**
         * @brief Get the Severity Type object
         * 
         * @return VirusSeverity 
         */
        VirusSeverity getSeverityType();

       /**
        * @brief Set the Severity Type object
        * 
        * @param typeSeverity 
        */
        void setSeverityType(VirusSeverity typeSeverity);

};

#endif