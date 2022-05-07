#ifndef ABSTRACTDIALOG_H
#define ABSTRACTDIALOG_H

#include <vector>
#include <string>
#include "model/Virus.hpp"

enum class DialogType {
        LEVEL_UP, SPAWN
};

enum class DialogAnswers {
    YES, NO, PASS, UP_VIRUS_SPREAD_CHANCE, SPAWN, UP_VIRUS_LIVING_TIME, REDUCE_IMUNE_CHANCE
};

class AbstractDialog {
protected:
    DialogType _type;
    std::string _question;
    std::vector<DialogAnswers> _answers;
    int _ratio;
    std::string _chosenAnswer;
    Virus * _virus;
public:
    AbstractDialog();
    AbstractDialog(DialogType type, int ratio,Virus * virus);
    std::string getQuestion();
    std::vector<DialogAnswers> getAnswers();
    virtual bool isChoiceValid() = 0;
    virtual void applyChoice() = 0;
    void setChosenAnswer(std::string& chosen);
};

#endif