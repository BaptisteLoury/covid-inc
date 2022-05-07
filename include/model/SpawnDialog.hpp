#ifndef SPAWNDIALOG_H
#define SPAWNDIALOG_H

#include <map>
#include <string>
#include <vector>
#include "model/SpawnTile.hpp"
#include "model/AbstractDialog.hpp"
#include "model/Virus.hpp"

class SpawnDialog : virtual public AbstractDialog {
protected:
    std::vector<SpawnTile *> _spawns;
public:
    SpawnDialog();
    SpawnDialog(std::vector<SpawnTile *>& spawns, Virus * virus);
    bool isChoiceValid();
    void applyChoice();
};

#endif