#ifndef APPLICATION_H
#define APPLICATION_H

#include <ncurses.h>
#include <curses.h>
#include <iostream>
#include <vector>
#include "controller/MainController.hpp"
#include "utils/Timer.hpp"
#include "utils/WindowUtils.hpp"

class Application
{
private:
    MainController * controller;

public:
    Application();
    void run();
};


#endif