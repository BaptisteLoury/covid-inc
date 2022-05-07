#ifndef LEVELUPDIALOG_H
#define LEVELUPDIALOG_H

#include <map>
#include <string>
#include <vector>
#include "model/AbstractDialog.hpp"

class LevelUpDialog : virtual public AbstractDialog {
public:
    LevelUpDialog();
    LevelUpDialog(Virus * virus);
    bool isChoiceValid();
    void applyChoice();
};

#endif