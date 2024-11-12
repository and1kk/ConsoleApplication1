#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(double price, double maxSpeed, int year, std::string color, int numberOfDoors)
        : Vehicle(price, maxSpeed, year, color), numberOfDoors(numberOfDoors) {}

    void displayInfo() const override {
        std::cout << "Car: " << color << ", " << year << ", Price: " << price << ", Max Speed: " << maxSpeed << ", Doors: " << numberOfDoors << std::endl;
    }

    int getNumberOfDoors() const { return numberOfDoors; }
    void setNumberOfDoors(int doors) { numberOfDoors = doors; }
};

#endif // CAR_H
