#include "ParkingLot.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    ParkingLot lot(10);

    for (int i = 0; i < 5; ++i) lot.parkVehicle(new Car(i + 1));
    for (int i = 0; i < 3; ++i) lot.parkVehicle(new Bus(i + 101));
    for (int i = 0; i < 2; ++i) lot.parkVehicle(new Motorbike(i + 201));

    std::this_thread::sleep_for(std::chrono::seconds(16));

    int overstaying = lot.countOverstayingVehicles(15);
    std::cout << "Vehicles overstaying more than 15 seconds: " << overstaying << std::endl;

    return 0;
}
