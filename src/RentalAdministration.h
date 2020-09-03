#include <vector>
#include "Car.h"
#ifndef __RENTALADMINISTRATION_H__
#define __RENTALADMINISTRATION_H__


class RentalAdministration{
    public:
        RentalAdministration();

        bool Add(Car* car);

        bool RentCar(string licensePlate);

        double ReturnCar(string licensePlate, int kilometers);

        void CleanCar(string licensePlate);

        vector<Car*> GetCars() const;
    private:
        vector<Car*> cars;
        Car* FindCar(string licensePlate);
        Car* FindCarWithException(string licensePlate);
};

#endif // __RENTALADMINISTRATION_H__