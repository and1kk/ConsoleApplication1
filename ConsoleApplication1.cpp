#include <iostream>
#include "Car.h"
#include "Bicycle.h"
#include "Lorry.h"
#include "Garage.h"

int main() {
    Garage garage;

    // 1. Load vehicles from file
    garage.loadVehiclesFromFile("vehicles.txt");

    // 2. Add a new vehicle
    Vehicle* newCar = new Car(15000, 220, 2020, "Red", 4);
    garage.addVehicle(newCar);

    // 3. Remove a vehicle by index
    garage.removeVehicle(0);

    // 4. Search vehicles
    Vehicle* foundByType = garage.searchByType("Bicycle");
    if (foundByType) {
        foundByType->displayInfo();
    }

    Vehicle* foundByNumber = garage.searchByNumber(1);
    if (foundByNumber) {
        foundByNumber->displayInfo();
    }

    Vehicle* foundByTypeAndSpeed = garage.searchByTypeAndSpeed("Lorry", 80);
    if (foundByTypeAndSpeed) {
        foundByTypeAndSpeed->displayInfo();
    }

    // 5. Edit vehicle details
    garage.editVehicle(1, 16000, "Blue");

    // 6. Sort vehicles by speed
    garage.sortVehiclesBySpeed();

    // Display all vehicles
    garage.displayAllVehicles();

    return 0;
}
