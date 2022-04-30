#include "view/AbstractWindow.hpp"

AbstractWindow::AbstractWindow(int posX, int posY, int width, int height, WindowType type) : _type(type) {
    _win = subwin(stdscr, height, width, posY, posX);
}

WINDOW * AbstractWindow::getWindow() {
    return _win;
}

void AbstractWindow::draw() {}