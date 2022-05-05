#include "model/Virus.hpp"

Virus::Virus() : _lowSeverity(VirusSeverity::LOW),
                _mediumSeverity(VirusSeverity::MEDIUM),
                _highSeverity(VirusSeverity::HIGH),
                _level(1) {
    _livingTime.Start();
    _lastProke = _livingTime.GetElapsed();
}

Timer Virus::getLivingTime() {
    return _livingTime;
}

std::chrono::_V2::steady_clock::duration Virus::getLastProke() {
    return _lastProke;
}

void Virus::setLastProke() {
    _lastProke = _livingTime.GetElapsed();
}

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
