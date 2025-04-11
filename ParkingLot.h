#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"

class ParkingLot {
private:
    Vehicle** vehicles;
    int capacity;
    int count;

public:
    ParkingLot(int maxVehicles);
    ~ParkingLot();
    bool parkVehicle(Vehicle* v);
    bool unparkVehicle(int id);
    int getCount() const;
    int countOverstayingVehicles(int maxParkingDuration) const;
};

#endif
