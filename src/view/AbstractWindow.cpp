#include "view/AbstractWindow.hpp"
#include <string>

AbstractWindow::AbstractWindow(WindowType type) : _type(type) {}

WINDOW * AbstractWindow::getWindow() {
    return _win;
}

void AbstractWindow::endGame(Map& map) {

    std::string congrat;

    if(map.countInfested() == 0) {
        congrat = "Malheureusement, vous avez perdu !";
    }
    else {
        congrat = "Félicitation, vous avez remporté la partie !";
    }
    std::string keyToLeave = "<Appuyer sur une touche pour quitter le jeu>";

    mvprintw(LINES/2, (COLS - congrat.size())/2,"%s",congrat.c_str());
    mvprintw(LINES/2 + 1,(COLS - keyToLeave.size())/2,"%s",keyToLeave.c_str());

}