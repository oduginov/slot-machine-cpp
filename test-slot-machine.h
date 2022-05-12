//
// Created by dugol1 on 02.05.2022.
//

#ifndef SLOT_MACHINE_CPP_TEST_SLOT_MACHINE_H
#define SLOT_MACHINE_CPP_TEST_SLOT_MACHINE_H

#include "slot-machine.h"

class TestSlotMachine {
private:
    SlotMachine sm;
public:
    TestSlotMachine(SlotMachine sm);
    void testWindow();
    double getRTP();
    void testPay();
    std::vector<double> testSymbolPayments();
};

#endif //SLOT_MACHINE_CPP_TEST_SLOT_MACHINE_H
