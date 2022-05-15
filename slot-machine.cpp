//
// Created by Oleg Duginov on 29.04.2022.
//

#include "slot-machine.h"

SlotMachine::SlotMachine(const std::vector<Reel> &baseReels, const std::vector<Reel> &freeReels,
                         const std::vector<std::vector<double>> &payoff,
                         const std::vector<std::vector<unsigned int>> &winlines,
                         unsigned int height) : baseReels(baseReels), freeReels(freeReels), payoff(payoff),
                                                winlines(winlines), window(height),
                                                symbolPayments(13, 0) {
    lines = winlines.size();
    totalBet = bet * lines;
    std::cout << "lines: " << lines << std::endl;
}


void SlotMachine::setBet(unsigned int bet_) {
    if (bets.find(bet) != bets.end()) {
        bet = bet_;
        totalBet = bet * lines;
    } else {
        throw std::exception();
    }
}

void SlotMachine::play(std::vector<Reel> &reels) {
    window.initWindow(reels);
    pay2();
    updateFreeGames();
}

unsigned int SlotMachine::getTotalBet() const {
    return totalBet;
}

std::vector<Reel> SlotMachine::getBaseReels() const {
    return baseReels;
}

unsigned int SlotMachine::payForLine(const std::vector<unsigned int> &line, unsigned int symbol) {
    unsigned int i = 0;
    unsigned int countWild = 0, alpha = 1;
    for (auto x: line) {
        if (x == wild) {
            countWild++;
        }
        if (x == symbol || x == wild) {
            i++;
        } else {
            break;
        }
    }
    if (i == 0) {
        return 0;
    }
    if (isBaseMode) {
        if (countWild > 0 && symbol != wild) {
            alpha = 2;
        }
    } else {
        if (countWild != window.getWidth()) {
            if (countWild > 0 && symbol != wild) {
                alpha = 6;
            } else {
                alpha = 3;
            }
        }
    }
    return alpha * payoff[symbol][i - 1];
}

unsigned int SlotMachine::pay2() {
    double currentPayment = 0;
    auto w = window.getWindow();
    for (const auto &pattern: winlines) {
        std::vector<unsigned int> payline(window.getWidth());
        for (unsigned int i = 0; i < window.getWidth(); i++) {
            payline[i] = w[i][pattern[i]];

        }
        double sum = 0;
        unsigned int symb = 0;
        for (unsigned int symbol: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}) {
            auto point = payForLine(payline, symbol);
            if (sum < point) {
                sum = point;
                symb = symbol;
            }
        }

        if (!isBaseMode) {
            symbolPayments[symb] += sum;
        }
        currentPayment += sum;
    }
    currentPayment += payForScatters();
//    currentPayment *= lines / 10.0;
    payment += currentPayment;
    return currentPayment;
}

std::vector<double> SlotMachine::getSymbolPayments() {
    return symbolPayments;
}

unsigned int SlotMachine::payForScatters() {
    int i = 0;
    for (const auto &col: window.getWindow()) {
        if (std::find(col.begin(), col.end(), scatter) != col.end()) {
            i++;
        }
    }
    if (i == 0) {
        return 0;
    }
    if (!isBaseMode) {
        symbolPayments[scatter] += 3 * payoff[scatter][i - 1];
        return 3 * payoff[scatter][i - 1];
    }
//    symbolPayments[scatter] += payoff[scatter][i - 1];
    return payoff[scatter][i - 1];
}

void SlotMachine::setWindow(Window w) {
    window = w;
}

unsigned int SlotMachine::getPayment() const {
    return payment;
}

Window SlotMachine::getWindow() const {
    return window;
}

std::vector<std::vector<unsigned int>> SlotMachine::getWinlines() const {
    return winlines;
}

void SlotMachine::simulateGame(unsigned int iters) {
    payment = 0;
    freeGames = 0;
    freeSpins = 0;
    for (unsigned int i = 0; i < iters; i++) {
        isBaseMode = true;
        play(baseReels);
        while (freeGames > 0) {
            freeSpins++;
            isBaseMode = false;
            play(freeReels);
            freeGames--;
        }
    }
}

void SlotMachine::updateFreeGames() {
    auto w = window.getWindow();
    unsigned int c = 0;
    for (const auto &v: w) {
        for (const auto &item: v) {
            if (item == scatter) {
                c++;
            }
        }
    }
    if (c >= 3) {
        freeGames += 15;
    }
}

unsigned int SlotMachine::getFreeSpins() const {
    return freeSpins;
}
