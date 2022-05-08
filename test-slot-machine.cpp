//
// Created by Oleg Duginov on 02.05.2022.
//

#include "test-slot-machine.h"

void TestSlotMachine::testWindow() {
    std::vector<std::vector<unsigned int>> window;
    {
        window = {{0, 0, 0},
                  {0, 0, 0},
                  {0, 0, 0},
                  {0, 0, 0},
                  {0, 0, 0}};
    }
//    {
//        window = {{4,  9,  0},
//                  {6,  7,  9},
//                  {9,  1,  6},
//                  {11, 10, 4},
//                  {6,  7,  1}};
//    }
//    {
//        window = {{9,  0,  8},
//                  {2,  10, 11},
//                  {9,  10, 4},
//                  {12, 4,  11},
//                  {7,  3,  8}};
//    }
    Window w(3, 5, window);
    std::cout << w;
    sm.setWindow(w);
    std::cout << sm.pay2();
}

TestSlotMachine::TestSlotMachine(SlotMachine sm) : sm(sm) {
}

double TestSlotMachine::getRTP() {
    unsigned int iter = 1'000'000;
    sm.simulateGame(iter);
    return sm.getPayment() * 100.0 / (iter * sm.getTotalBet());
}

void TestSlotMachine::testPay() {
    auto reels = sm.getBaseReels();
    sm.play(reels);
    std::cout << sm.getWindow();
    std::cout << sm.pay2();
}