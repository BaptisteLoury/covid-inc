#ifndef TILEUTILS_H
#define TILEUTILS_H

#include <string>
#include <vector>

class TileUtils {
public:
    static const char * initChar(const std::string& c);

    static std::vector<std::vector<const char *>> CITY_ASSO;
};

#endif