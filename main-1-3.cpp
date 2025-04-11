#include <iostream>
#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot lot(10);

    for (int i = 1; i <= 5; ++i) {
        lot.parkVehicle(new Car(i));
    }

    for (int i = 6; i <= 8; ++i) {
        lot.parkVehicle(new Bus(i));
    }

    for (int i = 9; i <= 10; ++i) {
        lot.parkVehicle(new Motorbike(i));
    }

    int overstaying = lot.countOverstayingVehicles(15);
    std::cout << "Number of overstaying vehicles: " << overstaying << std::endl;
    
    return 0;
}