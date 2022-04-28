#include <ncurses.h>
#include <vector>
#include "view/AbstractWindow.hpp"

class Application
{
private:
    WINDOW * _map;
    WINDOW * _legend;
    WINDOW * _dialog;
    WINDOW * _stats;
    std::vector<AbstractWindow *> windows;

    void windowsSetup();
    void initWindows();
    void drawBorders();
public:
    Application();
    void run();
};


