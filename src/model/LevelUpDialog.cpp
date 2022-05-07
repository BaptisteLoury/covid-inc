#include "model/LevelUpDialog.hpp"
#include "utils/DialogUtils.hpp"

LevelUpDialog::LevelUpDialog() : AbstractDialog() {}

LevelUpDialog::LevelUpDialog(Virus * virus) :
    AbstractDialog(DialogType::LEVEL_UP, 0,virus) {
        _question = DialogUtils::getAssociatedText(DialogType::LEVEL_UP);
        _answers.push_back(DialogAnswers::UP_VIRUS_SPREAD_CHANCE);
        _answers.push_back(DialogAnswers::UP_VIRUS_LIVING_TIME);
        _answers.push_back(DialogAnswers::REDUCE_IMUNE_CHANCE);
}

bool LevelUpDialog::isChoiceValid() {
    bool found = false;
    try {
        int choice = std::stoi(_chosenAnswer);
        found = choice == 0 || choice == 1 || choice == 2;
    }
    catch(std::invalid_argument& e) {}

    return found;
}
void LevelUpDialog::applyChoice() {
    int choice = std::stoi(_chosenAnswer);


    switch (choice)
    {
    case 0:
        _virus->getSeverity(VirusSeverity::LOW)->upSpreadChance(5.0f);
        break;
    case 1:
        _virus->getSeverity(VirusSeverity::LOW)->upLifetime(1.0f);
        break;
    case 2:
        _virus->getSeverity(VirusSeverity::LOW)->upImmunityChance(5.0f);
        break;
    default:
        break;
    }

    }