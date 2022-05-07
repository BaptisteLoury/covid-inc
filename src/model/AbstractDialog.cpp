#include "model/AbstractDialog.hpp"

AbstractDialog::AbstractDialog() {}
AbstractDialog::AbstractDialog(DialogType type, int ratio) :
    _type(type), _ratio(ratio) {}

std::string AbstractDialog::getQuestion() {
    return _question;
}

std::vector<DialogAnswers> AbstractDialog::getAnswers() {
    return _answers;
}

void AbstractDialog::setChosenAnswer(std::string& chosen) {
    _chosenAnswer = chosen;
}