#include <iostream>
#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot lot(10);
    
    while (lot.getCount() < 10) {
        std::cout << "Current vehicles in lot: " << lot.getCount() << "/10" << std::endl;
        std::cout << "Enter vehicle type to park (1=Car, 2=Bus, 3=Motorbike): ";
        int type;
        std::cin >> type;
        
        int id = lot.getCount() + 1;
        Vehicle* vehicle = nullptr;
        
        switch (type) {
            case 1:
                vehicle = new Car(id);
                break;
            case 2:
                vehicle = new Bus(id);
                break;
            case 3:
                vehicle = new Motorbike(id);
                break;
            default:
                std::cout << "Invalid vehicle type" << std::endl;
                continue;
        }
        
        lot.parkVehicle(vehicle);
    }
    
    std::cout << "Parking lot is now full." << std::endl;
    
    std::cout << "Enter ID of vehicle to unpark: ";
    int idToUnpark;
    std::cin >> idToUnpark;
    lot.unparkVehicle(idToUnpark);
    
    return 0;
}