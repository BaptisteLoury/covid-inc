#include "utils/DialogUtils.hpp"


const std::string DialogUtils::QUESTION_SPAWN = "Choisir un numero pour faire apparaître le virus :";
const std::string DialogUtils::QUESTION_LEVEL_UP = "LEVEL UP, choisir une amélioration du virus :";

const std::string DialogUtils::ANSWER_YES = "Oui";
const std::string DialogUtils::ANSWER_NO = "Non";
const std::string DialogUtils::ANSWER_PASS = "Ok";
const std::string DialogUtils::ANSWER_SPAWN = "?";
const std::string DialogUtils::ANSWER_UP_VIRUS_SPREAD_CHANCE = "Augmenter la chance de diffusion du virus de %d%";

std::string DialogUtils::getAssociatedText(DialogType dt) {
    switch (dt)
    {
    case DialogType::LEVEL_UP:
        return QUESTION_LEVEL_UP;
    case DialogType::SPAWN:
        return QUESTION_SPAWN;
    default:
        return "";
    }
}
std::string DialogUtils::getAssociatedText(DialogAnswers da) {
    switch (da)
    {
    case DialogAnswers::YES:
        return ANSWER_YES;
    case DialogAnswers::NO:
        return ANSWER_NO;
    case DialogAnswers::SPAWN:
        return ANSWER_SPAWN;
    case DialogAnswers::PASS:
        return ANSWER_PASS;
    case DialogAnswers::UP_VIRUS_SPREAD_CHANCE:
        return ANSWER_UP_VIRUS_SPREAD_CHANCE;
    default:
        return "";
    }
}