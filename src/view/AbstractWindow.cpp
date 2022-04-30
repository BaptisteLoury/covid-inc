#include "view/AbstractWindow.hpp"

AbstractWindow::AbstractWindow(WindowType type) : _type(type) {}

WINDOW * AbstractWindow::getWindow() {
    return _win;
}

void AbstractWindow::draw() {}