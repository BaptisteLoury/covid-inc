#include "controller/MainController.hpp"
#include "controller/VirusController.hpp"
#include "view/MapWindow.hpp"
#include "view/LegendWindow.hpp"
#include "view/DialogWindow.hpp"
#include "view/StatsWindow.hpp"
#include "utils/MapUtils.hpp"
#include "model/SpawnDialog.hpp"
#include "model/LevelUpDialog.hpp"
#include "model/SpawnTile.hpp"
#include <time.h>
#include <iostream>

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
   

    MapUtils tool;
    std::vector<std::string> stringMap = tool.getMapTable();
    _map = Map(stringMap);

    _windows.push_back(new StatsWindow(&_virus, &_map));
    std::vector<SpawnTile *> firstSpawn = _map.getSpawnTiles();

    dynamic_cast<DialogWindow*>(_windows[2])->setDialog(new SpawnDialog(firstSpawn,&_virus));

    std::srand(time(NULL));
}

void MainController::draw() {
    for(int i=0; i < _windows.size(); i++) {
        _windows[i]->draw();
    }
}

void MainController::updateGame() {

    VirusController::spreadVirus(_map,&_virus,dynamic_cast<DialogWindow*>(_windows[2]));

    // MapWindow
    dynamic_cast<MapWindow*>(_windows[0])->updateMap(_map.getTiles());
        


}

void MainController::interactWithUser() {
    _virus.getLivingTime().Stop();

    while(!dynamic_cast<DialogWindow*>(_windows[2])->launchDialog()) {
        wclear(_windows[2]->getWindow());
        _windows[2]->draw();
    }
    dynamic_cast<DialogWindow*>(_windows[2])->deleteDialog();

    _virus.getLivingTime().Start();
}


bool MainController::isGameFinished(){
    return (_map.percentageInfested()>90.0)
        || (_map.hasGameBegun() && _map.countInfested() == 0);
}

void MainController::postGameEvent() {
    clear();

    AbstractWindow::endGame(_map);

    refresh();
    getch();
}