//
// Created by manicqin on 17/09/18.
//

#ifndef INC_04_CMAKE_JS_LIBRARY_H
#define INC_04_CMAKE_JS_LIBRARY_H

#include <string>
#include <algorithm>
#include <map>
namespace powerup {
    std::string reverse_string(std::string const& str);
    int         sum_int(int val1, int val2);
    double      distance(double x1, double y1, double x2, double y2);
    std::map<std::string, int>  count_words(std::string const& text);
}

#endif //INC_04_CMAKE_JS_LIBRARY_H
