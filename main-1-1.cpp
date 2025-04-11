#include "Vehicle.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    Car c(1);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Bus b(2);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Motorbike m(3);

    std::cout << "Car duration: " << c.getParkingDuration() << " seconds" << std::endl;
    std::cout << "Bus duration: " << b.getParkingDuration() << " seconds" << std::endl;
    std::cout << "Motorbike duration: " << m.getParkingDuration() << " seconds" << std::endl;

    return 0;
}
