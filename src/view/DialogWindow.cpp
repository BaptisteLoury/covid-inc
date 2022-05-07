#include <ncurses.h>
#include "view/DialogWindow.hpp"
#include "utils/WindowUtils.hpp"
#include "utils/DialogUtils.hpp"
#include <iostream>

DialogWindow::DialogWindow() 
    : AbstractWindow(WindowType::DIALOG) {
        _win = subwin(stdscr, WindowUtils::DIALOG_HEIGHT, WindowUtils::DIALOG_WIDTH, WindowUtils::DIALOG_POSY, WindowUtils::DIALOG_POSX);
    }

void DialogWindow::draw() {
    box(_win, ACS_VLINE, ACS_HLINE);
}

bool DialogWindow::launchDialog() {
    if(_dialog == nullptr)
        return true;

    mvwprintw(_win,2,2,"%s",_dialog->getQuestion().c_str());

    int i;
    for(i=0; i < _dialog->getAnswers().size(); i++) {
        mvwprintw(_win,4+i,2,"%d: %s",i,DialogUtils::getAssociatedText(_dialog->getAnswers()[i]).c_str());
    }
    std::string s{20, '\0'};
    mvwscanw(_win,5+i,2,"%s", s.c_str());
    _dialog->setChosenAnswer(s);

    bool isValid = _dialog->isChoiceValid();
    if(isValid) {
        _dialog->applyChoice();
    }
    return isValid;
}

AbstractDialog * DialogWindow::getDialog() {
    return _dialog;
}
void DialogWindow::setDialog(AbstractDialog * dialog) {
    _dialog = dialog;
}

void DialogWindow::deleteDialog() {
    if(_dialog != nullptr) {
        AbstractDialog * d = _dialog;
        _dialog = nullptr;
    }
}