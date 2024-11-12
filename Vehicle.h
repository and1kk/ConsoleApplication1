#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    double price;
    double maxSpeed;
    int year;
    std::string color;

public:
    Vehicle(double price, double maxSpeed, int year, std::string color)
        : price(price), maxSpeed(maxSpeed), year(year), color(color) {}

    virtual ~Vehicle() {}

    virtual void displayInfo() const = 0;

    // Getters and Setters
    double getPrice() const { return price; }
    void setPrice(double p) { price = p; }

    double getMaxSpeed() const { return maxSpeed; }
    void setMaxSpeed(double speed) { maxSpeed = speed; }

    int getYear() const { return year; }
    void setYear(int y) { year = y; }

    std::string getColor() const { return color; }
    void setColor(const std::string& c) { color = c; }
};

#endif // VEHICLE_H
