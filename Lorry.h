#ifndef LORRY_H
#define LORRY_H

#include "Vehicle.h"
#include <iostream>

class Lorry : public Vehicle {
private:
    double loadCapacity;

public:
    Lorry(double price, double maxSpeed, int year, std::string color, double loadCapacity)
        : Vehicle(price, maxSpeed, year, color), loadCapacity(loadCapacity) {}

    void displayInfo() const override {
        std::cout << "Lorry: " << color << ", " << year << ", Price: " << price << ", Max Speed: " << maxSpeed << ", Load Capacity: " << loadCapacity << " tons" << std::endl;
    }

    double getLoadCapacity() const { return loadCapacity; }
    void setLoadCapacity(double capacity) { loadCapacity = capacity; }
};

#endif // LORRY_H
