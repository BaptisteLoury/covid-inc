#include "core/Application.hpp"

Application::Application() {

}

void Application::run(){
    initscr();
    start_color();
    use_default_colors();

    WindowUtils::initConsts();

    controller = MainController::s_getSingleton();
    
    Timer time;
    time.Start();
    std::chrono::_V2::steady_clock::duration lastLoop = time.GetElapsed();

    while(1) {
        controller->updateGame();
        if(time.diffWithCurrent(lastLoop) > 50) {
            lastLoop = time.GetElapsed();
            clear();
            controller->draw();
            refresh();
            controller->interactWithUser();
        }
    }
    
    endwin();               // Restaure les paramètres par défaut du terminal
}