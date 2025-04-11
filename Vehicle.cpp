#include "Vehicle.h"
#include <ctime>

Vehicle::Vehicle(int id) {
    ID = id;
    timeOfEntry = std::time(nullptr);
}

int Vehicle::getID() const {
    return ID;
}

Car::Car(int id) : Vehicle(id) {}
int Car::getParkingDuration() const {
    int duration = std::difftime(std::time(nullptr), timeOfEntry);
    return static_cast<int>(duration * 0.9);
}

Bus::Bus(int id) : Vehicle(id) {}
int Bus::getParkingDuration() const {
    int duration = std::difftime(std::time(nullptr), timeOfEntry);
    return static_cast<int>(duration * 0.75);
}

Motorbike::Motorbike(int id) : Vehicle(id) {}
int Motorbike::getParkingDuration() const {
    int duration = std::difftime(std::time(nullptr), timeOfEntry);
    return static_cast<int>(duration * 0.85);
}
