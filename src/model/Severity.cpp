#include "model/Severity.hpp"


Severity::Severity(){
            this->_spreadChance=100.0;
            this->_lifetime=100.0;
            // this->_evolveChance=50.0;
            this->_scorePerSec=1;
            this->_severityType=VirusSeverity::LOW;
}

Severity::Severity(VirusSeverity severityType){
    switch (severityType)
      {
         case VirusSeverity::LOW:
            this->_spreadChance=100.0;
            this->_lifetime=100.0;
            // this->_evolveChance=50.0;
            this->_scorePerSec=1;
            this->_severityType=VirusSeverity::LOW;
            
            break;

        case VirusSeverity::MEDIUM:
             this->_spreadChance=100.0;
            this->_lifetime=100.0;
            // this->_evolveChance=50.0;
            this->_scorePerSec=1;
            this->_severityType=VirusSeverity::MEDIUM;
            
            break;

        case VirusSeverity::HIGH:

            this->_spreadChance=100.0;
            this->_lifetime=100.0;
            // this->_evolveChance=50.0;
            this->_scorePerSec=1;
            this->_severityType=VirusSeverity::HIGH;
            
            break;

         default:

            this->_spreadChance=100.0;
            this->_lifetime=100.0;
            // this->_evolveChance=50.0;
            this->_scorePerSec=1;
            this->_severityType=VirusSeverity::LOW;
            
            break;
      }

}


float Severity::getSpreadChance(){
    return _spreadChance;
}


void Severity::setSpreadChance(float newSpreadChance){
    _spreadChance=newSpreadChance;
}

float Severity::getLifetime(){
    return _lifetime;
}


void Severity::setLifetime(float newLifeTime){
    _lifetime=newLifeTime;
}


float Severity::getEvolveChance(){
    return _evolveChance;
}

void Severity::setEvolveChance(float newEvolveChance){
    _evolveChance=newEvolveChance;
}

int Severity::getScorePerSec(){
    return _scorePerSec;
}

void Severity::setScorePerSec(int newScorePerSec){
    _scorePerSec=newScorePerSec;
}