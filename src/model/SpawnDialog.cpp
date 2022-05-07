#include "model/SpawnDialog.hpp"
#include "utils/DialogUtils.hpp"
#include <iostream>


SpawnDialog::SpawnDialog() : AbstractDialog() {}

SpawnDialog::SpawnDialog(std::vector<SpawnTile *>& spawns) :
    AbstractDialog(DialogType::SPAWN, 0), _spawns(spawns) {
        _question = DialogUtils::getAssociatedText(DialogType::SPAWN);
    }

bool SpawnDialog::isChoiceValid() {
    bool found = false;
    try {
        int choice = std::stoi(_chosenAnswer);
        int i = 0;
        while(i < _spawns.size() && !found) {
            if(choice == std::stoi(_spawns[i]->getChar())) {
                found = true;
            }
            i++;
        }
    }
    catch(std::invalid_argument& e) {}

    return found;
}
void SpawnDialog::applyChoice() {
    int choice = std::stoi(_chosenAnswer);
    int i = 0;
    bool found = false;
    while(i < _spawns.size() && !found) {
        if(choice == std::stoi(_spawns[i]->getChar())) {
            found = true;
            _spawns[i]->infect();
        }
        i++;
    }
}