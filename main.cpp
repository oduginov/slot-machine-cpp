//
// Created by Oleg Duginov on 29.04.2022.
//

#include "reel.h"
#include "slot-machine.h"
#include <iomanip>
#include "test-slot-machine.h"
#include "util.h"



std::ostream &operator<<(std::ostream &os, const std::map<unsigned int, unsigned int> &m) {
    for (auto pair: m) {
        os << "\'" << pair.first << "\' : " << pair.second << std::endl;
    }
    return os;
}


int main() {
    Reel baseReel1 = Reel(
            {9, 10, 8, 2, 6, 5, 9, 7, 10, 12, 5, 10, 3, 6, 4, 9, 0, 8, 11, 7, 9, 6, 1, 9, 4, 7, 8, 3, 6, 8});
    Reel baseReel2 = Reel(
            {8, 11, 3, 10, 5, 7, 4, 2, 10, 11, 3, 7, 10, 4, 7, 10, 5, 11, 3, 8, 6, 5, 7, 0, 6, 7, 9, 1, 8, 10, 11, 4, 9,
             6, 2, 10, 12, 1, 7, 10, 5, 7, 9});
    Reel baseReel3 = Reel(
            {7, 8, 9, 5, 9, 2, 10, 8, 3, 6, 5, 8, 9, 1, 6, 4, 11, 6, 2, 9, 10, 4, 6, 2, 9, 8, 0, 9, 3, 12, 8, 1, 7, 4,
             10, 3, 6, 11, 1, 10, 7, 8, 11});
    Reel baseReel4 = Reel(
            {6, 7, 4, 10, 1, 12, 4, 11, 5, 7, 9, 0, 8, 2, 4, 11, 3, 10, 5, 11, 10, 2, 7, 9, 0, 8, 2, 6, 10, 3, 8, 1, 6,
             4, 10, 5, 11, 10, 4, 11, 7, 5, 9});
    Reel baseReel5 = Reel(
            {5, 5, 10, 3, 11, 4, 6, 1, 10, 7, 1, 11, 10, 2, 7, 10, 3, 11, 5, 7, 11, 1, 7, 6, 0, 7, 3, 8, 12, 11, 10, 4,
             9, 2, 6, 7, 1, 8, 5, 10, 9, 1, 11});

    Reel freeReel1 = Reel(
            {3, 6, 4, 9, 0, 8, 11, 5, 9, 7, 1, 6, 4, 10, 11, 3, 6, 8, 12, 10, 8, 2, 6, 5, 10, 8, 1, 7, 9, 10, 2, 7, 9});
    Reel freeReel2 = Reel(
            {0, 6, 7, 9, 12, 11, 3, 10, 6, 2, 9, 4, 10, 3, 4, 9, 12, 11, 5, 8, 4, 9, 8, 10, 5, 7, 0, 6, 7, 10, 1, 8, 3,
             9, 5, 7});
    Reel freeReel3 = Reel(
            {7, 11, 12, 8, 7, 1, 11, 10, 5, 11, 2, 4, 6, 11, 12, 8, 10, 5, 2, 6, 5, 10, 9, 8, 0, 9, 3, 6, 7, 1, 4, 9, 8,
             0, 9, 3});
    Reel freeReel4 = Reel(
            {9, 12, 7, 4, 11, 9, 5, 6, 8, 10, 1, 5, 9, 12, 7, 4, 8, 2, 11, 6, 3, 7, 9, 0, 8, 2, 6, 10, 3, 6, 1, 7, 4,
             10, 3, 5});
    Reel freeReel5 = Reel(
            {11, 12, 5, 10, 6, 7, 8, 4, 10, 3, 8, 1, 11, 12, 5, 10, 3, 9, 4, 2, 9, 7, 6, 0, 7, 3, 8, 5, 11, 6, 4, 9, 2,
             6, 7, 1});

    std::vector<std::vector<unsigned int>> payoff = {{0, 10, 250, 2500, 9000},// 0
                                                     {0, 2,  25,  125,  750}, // 1
                                                     {0, 2,  25,  125,  750}, // 2
                                                     {0, 0,  20,  100,  400}, // 3
                                                     {0, 0,  15,  75,   250}, // 4
                                                     {0, 0,  15,  75,   250}, // 5
                                                     {0, 0,  10,  50,   125}, // 6
                                                     {0, 0,  10,  50,   125}, // 7
                                                     {0, 0,  5,   25,   100}, // 8
                                                     {0, 0,  5,   25,   100}, // 9
                                                     {0, 0,  5,   25,   100}, // 10
                                                     {0, 2,  5,   25,   100}, // 11
                                                     {0, 2,  5,   20,   500}};  // {0, 20, 50,  200,  5000};

    std::vector<std::vector<unsigned int>> winlines = {{2, 2, 2, 2, 2},
                                                       {1, 1, 1, 1, 1},
                                                       {0, 0, 0, 0, 0},
                                                       {0, 1, 2, 1, 0},
                                                       {2, 1, 0, 1, 2},
                                                       {1, 2, 2, 2, 1},
                                                       {1, 0, 0, 0, 1},
                                                       {2, 2, 1, 0, 0},
                                                       {0, 0, 1, 2, 2},
                                                       {2, 1, 1, 1, 0}};
    SlotMachine sm({baseReel1, baseReel2, baseReel3, baseReel4, baseReel5},
                   {freeReel1, freeReel2, freeReel3, freeReel4, freeReel5}, payoff, winlines, 3);
    TestSlotMachine test(sm);
    std::vector<double> rtp;
    for (int i = 0; i < 10; i++) {
        rtp.push_back(test.getRTP());
    }
    std::cout << rtp;
    return 0;
}