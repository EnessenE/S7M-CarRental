#include <stdexcept>
using namespace std;

#include "RentalAdministration.h"

RentalAdministration::RentalAdministration()
{
}

bool RentalAdministration::Add(Car *car)
{
    if (car == NULL)
    {
        throw std::invalid_argument("Car doesn't exist.");
    }

    if (FindCar(car->GetLicensePlate()) != NULL)
    {
        return false;
    }
    //push_back adds to list/array/vector
    cars.push_back(car);
}

bool RentalAdministration::RentCar(string licensePlate)
{
    if (licensePlate.length() == 0)
    {
        throw new std::invalid_argument("No licenseplate given");
    }

    Car *car = FindCarWithException(licensePlate);
    return car->Rent();
}

double RentalAdministration::ReturnCar(string licensePlate, int kilometers)
{
    if (licensePlate.length() == 0)
    {
        throw new std::invalid_argument("No licenseplate given");
    }

    Car *car = FindCarWithException(licensePlate);
    if (car->GetIsAvailable())
    {
        throw new std::invalid_argument("Car is not rented");
    }
    return car->Return(kilometers);
}

void RentalAdministration::CleanCar(string licensePlate)
{
    if (licensePlate.length() == 0)
    {
        throw new std::invalid_argument("No licenseplate given");
    }

    Car *car = FindCarWithException(licensePlate);
    car->Clean();
}

vector<Car*> RentalAdministration::GetCars() 
{
    return cars;
}

Car *RentalAdministration::FindCar(string licensePlate)
{
    for (Car *car : cars)
    {
        if (car->GetLicensePlate() == licensePlate)
        {
            return car;
        }
    }
    return NULL;
}

Car* RentalAdministration::FindCarWithException(string licensePlate) 
{
    Car* car = FindCar(licensePlate);
    if (car == NULL){
        throw std::out_of_range(" No car with this licenseplate in administration");
    }
    return car;
}

