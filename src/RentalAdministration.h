#ifndef __RENTALADMINISTRATION_H__
#define __RENTALADMINISTRATION_H__

#include <vector>
#include "Car.h"

class RentalAdministration{
    private:
        vector<Car*> cars;
        Car* FindCar(string licensePlate);
        Car* FindCarWithException(string licensePlate);

    public:
        RentalAdministration();

        bool Add(Car* car);

        bool RentCar(string licensePlate);

        double ReturnCar(string licensePlate, int kilometers);

        void CleanCar(string licensePlate);

        vector<Car*> GetCars() const;
};

#endif // __RENTALADMINISTRATION_H__