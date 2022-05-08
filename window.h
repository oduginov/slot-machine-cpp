//
// Created by Oleg Duginov on 30.04.2022.
//

#ifndef SLOT_MACHINE_CPP_WINDOW_H
#define SLOT_MACHINE_CPP_WINDOW_H

#include <vector>
#include <random>
#include <iostream>
#include "reel.h"
#include <iomanip>


class Window {
private:
    unsigned int height;
    unsigned int width = 0;
    std::vector<std::vector<unsigned int>> window;

public:
    Window(unsigned int height);

    Window(unsigned int height, unsigned int width, const std::vector<std::vector<unsigned int>> window);

    void initWindow(std::vector<Reel> &reels);

    std::vector<std::vector<unsigned int>> getWindow() const;

    unsigned int getWidth() const;

    friend std::ostream &operator<<(std::ostream &os, const Window& window);
};


#endif //SLOT_MACHINE_CPP_WINDOW_H
