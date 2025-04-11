#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    double duration = difftime(now, timeOfEntry);
    return static_cast<int>(duration * 0.9); 
}