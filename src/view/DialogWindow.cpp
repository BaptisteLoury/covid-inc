#include "view/DialogWindow.hpp"
#include "utils/WindowUtils.hpp"

DialogWindow::DialogWindow() 
    : AbstractWindow(WindowUtils::DIALOG_HEIGHT, WindowUtils::DIALOG_WIDTH, WindowUtils::DIALOG_POSY, WindowUtils::DIALOG_POSX, WindowType::DIALOG) {}

void DialogWindow::draw() {
    
}