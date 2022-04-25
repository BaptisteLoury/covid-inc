#include <ncurses.h>

class Application
{
private:
    WINDOW * _map;
    WINDOW * _menu;
public:
    Application();
    void run();
};


