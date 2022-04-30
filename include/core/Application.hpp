#ifndef APPLICATION_H
#define APPLICATION_H

#include <ncurses.h>
#include <vector>
#include "controller/MainController.hpp"

class Application
{
private:
    MainController * controller;

public:
    Application();
    void run();
};


#endif