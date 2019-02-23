//
// Created by manicqin on 17/09/18.
//

#include "library.h"

#include <iostream>
#include <algorithm>

#include <assert.h>

int main() {
    std::string str1 = powerup::reverse_string("1234");
    std::string str2 = "4321";
    assert(std::equal(str1.cbegin(),str1.cend(),str2.cbegin()));

    assert(powerup::sum_int(1 ,2) == 3);

    assert(powerup::distance(0,0,4,3) == 5.0);

    std::map<std::string, int> dictionary = powerup::count_words("boom boom boom bam");
    std::map<std::string, int> expected = { {"boom", 3}, {"bam",1} };
    assert(std::equal(dictionary.cbegin(),dictionary.cend(), expected.cbegin()));


    std::cout << "If you can see this then everything is ok!" << std::endl;
    return 0;
}