//
// Created by Oleg Duginov on 30.04.2022.
//

#include "reel.h"

Reel::Reel(const std::vector<unsigned int> &ids) : ids(ids),
                                                   distrib(std::uniform_int_distribution<>(0, ids.size() - 1)) {
    std::random_device rd;
    gen = std::mt19937(rd());
}

std::vector<unsigned int> Reel::spin(unsigned int height) {
    unsigned int stop = distrib(gen);
    std::vector<unsigned int> line(height);
    for (int i = 0; i < height; i++) {
        line[i] = ids[(stop + i) % ids.size()];
    }
    return line;
}

std::map<unsigned int, unsigned int> Reel::getStatistics() {
    std::map<unsigned int, unsigned int> stat;
    for (auto item: ids) {
        stat[item]++;
    }
    return stat;
}