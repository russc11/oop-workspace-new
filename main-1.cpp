#include "Utils.h"
#include <iostream>
#include <random>

std::tuple<int, int> Utils::generateRandomPos(int gridWidth, int gridHeight) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> xDist(0, gridWidth - 1);
    std::uniform_int_distribution<> yDist(0, gridHeight - 1);
    return std::make_tuple(xDist(gen), yDist(gen));
}

double Utils::calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
    int x1 = std::get<0>(pos1);
    int y1 = std::get<1>(pos1);
    int x2 = std::get<0>(pos2);
    int y2 = std::get<1>(pos2);
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    auto pos1 = Utils::generateRandomPos(100, 100);
    auto pos2 = Utils::generateRandomPos(100, 100);
    
    std::cout << "Position 1: (" << std::get<0>(pos1) << ", " << std::get<1>(pos1) << ")\n";
    std::cout << "Position 2: (" << std::get<0>(pos2) << ", " << std::get<1>(pos2) << ")\n";
    
    double distance = Utils::calculateDistance(pos1, pos2);
    std::cout << "Distance between positions: " << distance << std::endl;
    
    return 0;
}