#include <ncurses.h>

class AbstractWindow {
private:
    WINDOW * _win;
public:
    virtual void initWindow();
    virtual void drawBorders();
};