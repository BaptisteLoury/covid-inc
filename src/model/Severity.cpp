#include "model/Severity.hpp"


Severity::Severity(){
            _spreadChance=30;
            _lifetime=10;
            _immuneChance=50.0;
            // _evolveChance=50.0;
            _scorePerSec=1;
            _severityType=VirusSeverity::LOW;
}

Severity::Severity(VirusSeverity severityType){
    switch (severityType)
      {
         case VirusSeverity::LOW:
            _spreadChance=50.0;
            _lifetime=10.0;
            _immuneChance=50.0;
            // _evolveChance=50.0;
            _scorePerSec=1;
            _severityType=VirusSeverity::LOW;
            
            break;

        case VirusSeverity::MEDIUM:
             _spreadChance=100.0;
            _lifetime=100.0;
            _immuneChance=50.0;
            // _evolveChance=50.0;
            _scorePerSec=1;
            _severityType=VirusSeverity::MEDIUM;
            
            break;

        case VirusSeverity::HIGH:

            _spreadChance=100.0;
            _lifetime=100.0;
            _immuneChance=50.0;
            // _evolveChance=50.0;
            _scorePerSec=1;
            _severityType=VirusSeverity::HIGH;
            
            break;

         default:

            _spreadChance=100.0;
            _lifetime=100.0;
            _immuneChance=50.0;
            // _evolveChance=50.0;
            _scorePerSec=1;
            _severityType=VirusSeverity::LOW;
            
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

float Severity::getImmuneChance() {
    return _immuneChance;
}

void Severity::upLifetime(float up) {
    _lifetime += up;
}
void Severity::upSpreadChance(float up) {
    _spreadChance += up;
}
void Severity::upImmunityChance(float up) {
    _immuneChance -= up;
}