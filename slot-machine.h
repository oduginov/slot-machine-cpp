//
// Created by Oleg Duginov on 29.04.2022.
//


#ifndef SLOT_MACHINE_CPP_SLOT_MACHINE_H
#define SLOT_MACHINE_CPP_SLOT_MACHINE_H

#include <set>
#include <vector>
#include <random>
#include "reel.h"
#include "window.h"
#include <algorithm>
//#include "util.h"

class SlotMachine {
private:
    unsigned int lines;
    unsigned int bet = 1;
    unsigned int totalBet;
    std::set<unsigned int> bets = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20};
    std::vector<Reel> baseReels;
    std::vector<Reel> freeReels;
    Window window;
    std::vector<std::vector<double>> payoff;
    std::vector<std::vector<unsigned int>> winlines;
    unsigned int wild = 0;
    unsigned int scatter = 12;
    double payment = 0;
    unsigned int freeGames = 0;
    bool isBaseMode = true;

    void updateFreeGames();

    std::vector<double> symbolPayments;


public:

    SlotMachine(const std::vector<Reel> &baseReels, const std::vector<Reel> &freeReels,
                const std::vector<std::vector<double>> &payoff,
                const std::vector<std::vector<unsigned int>> &winlines,
                unsigned int height);

    void play(std::vector<Reel> &reels);


    std::vector<double> getSymbolPayments();


    unsigned int pay2();

    unsigned int payForLine(const std::vector<unsigned int> &line, unsigned int symbol);

    unsigned int payForScatters();

    void switchMode();

    Window getWindow() const;

    std::vector<Reel> getBaseReels() const;

    void setWindow(Window w);

    std::vector<std::vector<unsigned int>> getWinlines() const;

    unsigned int getTotalBet() const;

    unsigned int getPayment() const;

    void setBet(unsigned int bet_);

    void simulateGame(unsigned int iters);

};

#endif //SLOT_MACHINE_CPP_SLOT_MACHINE_H
