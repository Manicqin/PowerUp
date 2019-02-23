//
// Created by manicqin on 17/09/18.
//

#include "library.h"
#include "utils.h"

#include <math.h>

namespace powerup {
    std::string reverse_string(std::string const& str) {
        std::string tmp = str;
        std::reverse(tmp.begin(), tmp.end());
        return tmp;
    }

    int sum_int(int val1, int val2) {
        return val1 + val2;
    }

    double distance(double pnt1_x, double pnt1_y, double pnt2_x, double pnt2_y) {
        double x = std::pow(pnt1_x - pnt2_x, 2);
        double y = std::pow(pnt1_y - pnt2_y, 2);

        return std::sqrt(x + y);
    }

    std::map<std::string, int>  count_words(std::string const& text) {
        std::map<std::string, int> dictionary;

        for (auto const& itm_line : split(text)) {

            auto itm = reduce(itm_line, "", " \t\n,\"'~/\\!()-?@.;<>{}[]_^:*&#$%|=");
            if(dictionary.find(itm) != dictionary.end()) {
                auto count = dictionary[itm];
                dictionary[itm] = ++count;
            } else {
                dictionary[itm] = 1;
            }
        }

        return dictionary;
    }
}