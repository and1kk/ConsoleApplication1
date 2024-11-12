#ifndef GARAGE_H
#define GARAGE_H

#include "Vehicle.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

class Garage {
private:
    std::vector<Vehicle*> vehicles;

public:
    ~Garage() {
        for (auto vehicle : vehicles) {
            delete vehicle;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void removeVehicle(int index) {
        if (index >= 0 && index < vehicles.size()) {
            delete vehicles[index];
            vehicles.erase(vehicles.begin() + index);
        }
    }

    Vehicle* searchByType(const std::string& type) {
        for (auto vehicle : vehicles) {
            if ((type == "Car" && dynamic_cast<Car*>(vehicle)) ||
                (type == "Bicycle" && dynamic_cast<Bicycle*>(vehicle)) ||
                (type == "Lorry" && dynamic_cast<Lorry*>(vehicle))) {
                return vehicle;
            }
        }
        return nullptr;
    }

    Vehicle* searchByNumber(int index) {
        if (index >= 0 && index < vehicles.size()) {
            return vehicles[index];
        }
        return nullptr;
    }

    Vehicle* searchByTypeAndSpeed(const std::string& type, double speed) {
        for (auto vehicle : vehicles) {
            if (((type == "Car" && dynamic_cast<Car*>(vehicle)) ||
                (type == "Bicycle" && dynamic_cast<Bicycle*>(vehicle)) ||
                (type == "Lorry" && dynamic_cast<Lorry*>(vehicle))) &&
                vehicle->getMaxSpeed() == speed) {
                return vehicle;
            }
        }
        return nullptr;
    }

    void editVehicle(int index, double price, const std::string& color) {
        if (index >= 0 && index < vehicles.size()) {
            vehicles[index]->setPrice(price);
            vehicles[index]->setColor(color);
        }
    }

    void sortVehiclesBySpeed() {
        std::sort(vehicles.begin(), vehicles.end(), [](Vehicle* a, Vehicle* b) {
            return a->getMaxSpeed() < b->getMaxSpeed();
            });
    }

    void displayAllVehicles() const {
        for (const auto& vehicle : vehicles) {
            vehicle->displayInfo();
        }
    }

    void loadVehiclesFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Could not open the file!" << std::endl;
            return;
        }

        while (!file.eof()) {
            std::string type;
            file >> type;

            if (type == "Car") {
                double price, maxSpeed;
                int year, doors;
                std::string color;
                file >> price >> maxSpeed >> year >> color >> doors;
                vehicles.push_back(new Car(price, maxSpeed, year, color, doors));
            }
            else if (type == "Bicycle") {
                double price, maxSpeed;
                int year;
                std::string color, bikeType;
                file >> price >> maxSpeed >> year >> color >> bikeType;
                vehicles.push_back(new Bicycle(price, maxSpeed, year, color, bikeType));
            }
            else if (type == "Lorry") {
                double price, maxSpeed, loadCapacity;
                int year;
                std::string color;
                file >> price >> maxSpeed >> year >> color >> loadCapacity;
                vehicles.push_back(new Lorry(price, maxSpeed, year, color, loadCapacity));
            }
        }

        file.close();
    }
};

#endif // GARAGE_H
