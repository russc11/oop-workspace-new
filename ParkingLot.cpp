#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int maxVehicles) {
    capacity = maxVehicles;
    count = 0;
    vehicles = new Vehicle*[capacity];
}

ParkingLot::~ParkingLot() {
    for (int i = 0; i < count; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

bool ParkingLot::parkVehicle(Vehicle* v) {
    if (count >= capacity) {
        std::cout << "The lot is full" << std::endl;
        return false;
    }
    vehicles[count++] = v;
    return true;
}

bool ParkingLot::unparkVehicle(int id) {
    for (int i = 0; i < count; ++i) {
        if (vehicles[i]->getID() == id) {
            delete vehicles[i];
            for (int j = i; j < count - 1; ++j) {
                vehicles[j] = vehicles[j + 1];
            }
            count--;
            return true;
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
    return false;
}

int ParkingLot::getCount() const {
    return count;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int result = 0;
    for (int i = 0; i < count; ++i) {
        if (vehicles[i]->getParkingDuration() > maxParkingDuration) {
            result++;
        }
    }
    return result;
}
