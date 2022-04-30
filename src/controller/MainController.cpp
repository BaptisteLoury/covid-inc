#include "controller/MainController.hpp"
#include "view/DialogWindow.hpp"

MainController * MainController::s_singleton = nullptr;

MainController * MainController::s_getSingleton() {
    if(s_singleton == nullptr) {
        s_singleton = new MainController();
    }
    return s_singleton;
}

MainController::MainController() {
    _windows.push_back(new DialogWindow);
}