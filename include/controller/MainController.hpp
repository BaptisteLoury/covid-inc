#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <vector>
#include "view/AbstractWindow.hpp"

class MainController {
private:
        static MainController * s_singleton;
        std::vector<AbstractWindow *> _windows;
        // VirusModel _virus;

        MainController();
public:
        static MainController * s_getSingleton();
        void handleEvents();
        bool isGameFinished();
};

#endif