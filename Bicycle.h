#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"
#include <iostream>

class Bicycle : public Vehicle {
private:
    std::string type; // e.g., mountain, road

public:
    Bicycle(double price, double maxSpeed, int year, std::string color, std::string type)
        : Vehicle(price, maxSpeed, year, color), type(type) {}

    void displayInfo() const override {
        std::cout << "Bicycle: " << color << ", " << year << ", Price: " << price << ", Max Speed: " << maxSpeed << ", Type: " << type << std::endl;
    }

    std::string getType() const { return type; }
    void setType(const std::string& t) { type = t; }
};

#endif // BICYCLE_H
