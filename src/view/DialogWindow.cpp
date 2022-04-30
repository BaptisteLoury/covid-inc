#include <ncurses.h>
#include "view/DialogWindow.hpp"
#include "utils/WindowUtils.hpp"
#include <iostream>

DialogWindow::DialogWindow() 
    : AbstractWindow(WindowType::DIALOG) {
        _win = subwin(stdscr, WindowUtils::DIALOG_HEIGHT, WindowUtils::DIALOG_WIDTH, WindowUtils::DIALOG_POSY, WindowUtils::DIALOG_POSX);
    }

void DialogWindow::draw() {
    box(_win, ACS_VLINE, ACS_HLINE);
}