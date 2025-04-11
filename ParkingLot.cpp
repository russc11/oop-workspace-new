#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), currentCount(0) {
    vehicles.reserve(capacity);
}

ParkingLot::~ParkingLot() {
    for (auto vehicle : vehicles) {
        delete vehicle;
    }
}

int ParkingLot::getCount() const {
    return currentCount;
}

void ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (currentCount >= maxCapacity) {
        std::cout << "The lot is full" << std::endl;
        delete vehicle;
        return;
    }
    vehicles.push_back(vehicle);
    currentCount++;
}

void ParkingLot::unparkVehicle(int id) {
    for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
        if ((*it)->getID() == id) {
            delete *it;
            vehicles.erase(it);
            currentCount--;
            return;
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int count = 0;
    for (const auto vehicle : vehicles) {
        if (vehicle->getParkingDuration() > maxParkingDuration) {
            count++;
        }
    }
    return count;
}