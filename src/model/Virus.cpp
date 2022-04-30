#include "model/Virus.hpp"
#include "model/Severity.hpp"

Virus::Virus(){

    this->_level=1;
    this->_lowSeverity= Severity(VirusSeverity::LOW);
    this->_mediumSeverity= Severity(VirusSeverity::MEDIUM);
    this->_highSeverity= Severity(VirusSeverity::HIGH);

}

short Virus::getLevel(){

    return _level;
}

void Virus::setLevel(short newLevel){

   _level=newLevel;

}

Severity Virus::getLowSeverity(){
    return _lowSeverity;
}

Severity Virus:: getMediumSeverity(){
    return _mediumSeverity;
}

Severity Virus::getHighSeverity(){
    return _highSeverity;
}

