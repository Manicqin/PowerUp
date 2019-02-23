//
// Created by manicqin on 22/08/18.
//

#ifndef INC_03_NAPI_UTILS_H
#define INC_03_NAPI_UTILS_H

#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s,
                                      const std::string& delimiter = " ");

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t");

std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t");


#endif //INC_03_NAPI_UTILS_H
