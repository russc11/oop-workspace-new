#include <iostream>
#include <vector>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    int numCars, numBuses, numMotorbikes;
    
    std::cout << "Enter number of cars to park: ";
    std::cin >> numCars;
    std::cout << "Enter number of buses to park: ";
    std::cin >> numBuses;
    std::cout << "Enter number of motorbikes to park: ";
    std::cin >> numMotorbikes;
    
    std::vector<Vehicle*> vehicles;

    for (int i = 1; i <= numCars; ++i) {
        vehicles.push_back(new Car(i));
    }
    
    for (int i = 1; i <= numBuses; ++i) {
        vehicles.push_back(new Bus(numCars + i));
    }

    for (int i = 1; i <= numMotorbikes; ++i) {
        vehicles.push_back(new Motorbike(numCars + numBuses + i));
    }

    for (const auto vehicle : vehicles) {
        std::cout << "Vehicle ID: " << vehicle->getID() 
                  << ", Parking Duration: " << vehicle->getParkingDuration() 
                  << " seconds" << std::endl;
    }

    for (auto vehicle : vehicles) {
        delete vehicle;
    }
    
    return 0;
}