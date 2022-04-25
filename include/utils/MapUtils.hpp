#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

class MapUtils
{
private:
    string _pathToParamFile;
    int _lines;
    int _colums;
    vector<string> _mapTable;

    void readMapFile();
public:
    MapUtils();
    vector<string> getMapTable();
};


