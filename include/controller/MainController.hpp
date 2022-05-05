#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <vector>
#include "view/AbstractWindow.hpp"
#include "model/Map.hpp"
#include "model/Virus.hpp"

class MainController {
private:
        static MainController * s_singleton;
        std::vector<AbstractWindow *> _windows;
        Map _map;
        Virus _virus;

        MainController();
public:
        static MainController * s_getSingleton();
        void handleEvents();
        bool isGameFinished();
        void draw();
        void updateGame();
        void interactWithUser();
};

#endif