#include <ncurses.h>
#include <iostream>
#include "../include/model/Virus.hpp"

using namespace std;

int main() {
    Virus a;

    cout << a.getSeverity(VirusSeverity::LOW)->getLifetime() << endl;

    a.getSeverity(VirusSeverity::LOW)->upLifetime(5.0f);

    cout << a.getSeverity(VirusSeverity::LOW)->getLifetime() << endl;
}  