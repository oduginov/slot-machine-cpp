//
// Created by Oleg Duginov on 30.04.2022.
//

#ifndef SLOT_MACHINE_CPP_REEL_H
#define SLOT_MACHINE_CPP_REEL_H

#include <vector>
#include <random>
#include <map>

class Reel {
private:
    std::vector<unsigned int> ids;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;

public:
    Reel();
    Reel(const std::vector<unsigned int>& ids);
    std::map<unsigned int, unsigned int> getStatistics();
    std::vector<unsigned int> spin(unsigned int height);
};

#endif //SLOT_MACHINE_CPP_REEL_H
