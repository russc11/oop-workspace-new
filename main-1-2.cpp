#include "ParkingLot.h"
#include <iostream>

int main() {
    ParkingLot lot(10);
    int choice, id;

    while (lot.getCount() < 10) {
        std::cout << "Enter vehicle type (1-Car, 2-Bus, 3-Motorbike): ";
        std::cin >> choice;
        std::cout << "Enter vehicle ID: ";
        std::cin >> id;

        Vehicle* v = nullptr;
        if (choice == 1) v = new Car(id);
        else if (choice == 2) v = new Bus(id);
        else if (choice == 3) v = new Motorbike(id);

        if (v) lot.parkVehicle(v);
    }

    std::cout << "Parking lot full.\nEnter ID to unpark: ";
    std::cin >> id;
    lot.unparkVehicle(id);

    return 0;
}
