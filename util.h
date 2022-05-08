//
// Created by dugol1 on 07.05.2022.
//
#ifndef SLOT_MACHINE_CPP_UTIL_H
#define SLOT_MACHINE_CPP_UTIL_H

#include <iostream>
#include <vector>
#include <iomanip>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    os << std::setfill(' ');
    unsigned int n;
    for (auto item: v) {
        n = 3;
        if (item >= 10) {
            n++;
        }
        os << std::setw(n) << item << " ";
    }
    return os;
}

#endif //SLOT_MACHINE_CPP_UTIL_H
