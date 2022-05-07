#include "model/Virus.hpp"  

Virus::Virus() : _lowSeverity(VirusSeverity::LOW),
                _mediumSeverity(VirusSeverity::MEDIUM),
                _highSeverity(VirusSeverity::HIGH),
                _level(1), _exp(0), _expCap(1000) {
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

short Virus::getLevel(){

    return _level;
}

void Virus::setLevel(short newLevel){

   _level=newLevel;

}

Severity * Virus::getSeverity(VirusSeverity vs) {
    switch (vs)
    {
    case VirusSeverity::LOW:
        return &_lowSeverity;
        break;
    case VirusSeverity::MEDIUM:
        return &_mediumSeverity;
        break;
    case VirusSeverity::HIGH:
        return &_highSeverity;
        break;
    default:
        return &_lowSeverity;
        break;
    }
}

int Virus::getExp() {
    return _exp;
}

bool Virus::addExp(int exp) {
    if(_level < 10) {
        _exp += exp;

        if(_exp > _expCap) {
            _exp = 0;
            _level++;
            _expCap *= 2;
            return true;
        }

    }
    return false;
}

int Virus::getExpCap() {
    return _expCap;
}