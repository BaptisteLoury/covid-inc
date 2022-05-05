#include <cstring>
#include "utils/TileUtils.hpp"

const char * TileUtils::initChar(const std::string& c) {
    char * tmp = new char [c.length()+1];
    strcpy( tmp, c.c_str() );
    return tmp;
}

std::vector<std::vector<const char *>> TileUtils::CITY_ASSO = {
        {"S","T","L"},
        {"M","B"},
        {"R","Y"},
        {"J","D","C"},
        {"N","P"}
    };