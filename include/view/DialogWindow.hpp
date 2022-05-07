#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include "view/AbstractWindow.hpp"
#include "model/AbstractDialog.hpp"

class DialogWindow : virtual public AbstractWindow {
private:
        AbstractDialog * _dialog;
public:
        DialogWindow();
        void draw();
        bool launchDialog();
        AbstractDialog * getDialog();
        void setDialog(AbstractDialog * dialog);
        void deleteDialog();
};

#endif