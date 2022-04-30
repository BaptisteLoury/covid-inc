#include "controller/MainController.hpp"
#include "view/MapWindow.hpp"
#include "view/LegendWindow.hpp"
#include "view/DialogWindow.hpp"
#include "view/StatsWindow.hpp"

MainController * MainController::s_singleton = nullptr;

MainController * MainController::s_getSingleton() {
    if(s_singleton == nullptr) {
        s_singleton = new MainController();
    }
    return s_singleton;
}

MainController::MainController() {
    _windows.push_back(new MapWindow);
    _windows.push_back(new LegendWindow);
    _windows.push_back(new DialogWindow);
    _windows.push_back(new StatsWindow);
}

void MainController::draw() {
    
}