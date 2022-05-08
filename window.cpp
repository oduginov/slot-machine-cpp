//
// Created by Oleg Duginov on 30.04.2022.
//

#include "window.h"

Window::Window(unsigned int height) {
    this->height = height;
}


void Window::initWindow(std::vector<Reel> &reels) {
    window.clear();
    width = reels.size();
    for (int i = 0; i < width; i++) {
        auto v = reels[i].spin(height);
        window.push_back(v);
    }
}

std::ostream &operator<<(std::ostream &os, const Window &w) {
    int n = 4;
    for (unsigned int i = 0; i < w.width; i++) {
        os << "reel " << (i + 1) << ": ";
        for (unsigned int j = 0; j < w.height; j++) {
            os << std::setw(n) << w.window[i][j];
        }
        os << std::endl;
    }
    return os;
}

std::vector<std::vector<unsigned int>> Window::getWindow() const {
    return window;
}

unsigned int Window::getWidth() const {
    return width;
}

Window::Window(unsigned int height, unsigned int width, const std::vector<std::vector<unsigned int>> window) : height(
        height), width(width), window(window) {}