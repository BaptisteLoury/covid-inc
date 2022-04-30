#ifndef SEVERITY_H
#define SEVERITY_H

enum class VirusSeverity{
        NONE, LOW, MEDIUM, HIGH
};


class Severity {
protected:
        const float _initSpreadChance;
        const float _initLifetime;
        const float _initEvolveChance;
        const int _initScorePerSec;
        float _spreadChance;
        float _lifetime;
        float _evolveChance;
        int _scorePerSec;
        VirusSeverity _severityType;
public:
        Severity(VirusSeverity severityType);
};

#endif