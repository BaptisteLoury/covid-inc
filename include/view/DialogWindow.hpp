#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include "view/AbstractWindow.hpp"

class DialogWindow : virtual public AbstractWindow {
private:
        // AbstractDialog * _dialog;
public:
        DialogWindow();
        void draw();
};

#endif