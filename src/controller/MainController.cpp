#include "controller/MainController.hpp"
#include "controller/VirusController.hpp"
#include "view/MapWindow.hpp"
#include "view/LegendWindow.hpp"
#include "view/DialogWindow.hpp"
#include "view/StatsWindow.hpp"
#include "utils/MapUtils.hpp"
#include "model/SpawnDialog.hpp"
#include "model/SpawnTile.hpp"
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
    _windows.push_back(new StatsWindow(_virus));

    MapUtils tool;
    std::vector<std::string> stringMap = tool.getMapTable();
    _map = Map(stringMap);

    std::vector<SpawnTile *> firstSpawn = _map.getSpawnTiles();

    dynamic_cast<DialogWindow*>(_windows[2])->setDialog(new SpawnDialog(firstSpawn));
}

void MainController::draw() {
    for(int i=0; i < _windows.size(); i++) {
        _windows[i]->draw();
    }
}

void MainController::updateGame() {

    VirusController::spreadVirus(_map,_virus);

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