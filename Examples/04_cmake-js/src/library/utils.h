//
// Created by manicqin on 19/09/18.
//

#ifndef EXAMPLE04_UTILS_H
#define EXAMPLE04_UTILS_H

#include <vector>
#include <string>

std::vector<std::string> split(const std::string& s,
                               const std::string& delimiter = " ");

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t");

std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t");


#endif //EXAMPLE04_UTILS_H
