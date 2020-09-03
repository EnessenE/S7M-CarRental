#include <stdexcept>
using namespace std;

#include "Car.h"
// TODO: implement your class methods here

bool Car::Rent() 
{
    if (!IsAvailable){
        return false;
    }
    IsAvailable = false;
    return true;
}

double Car::Return(int kilometers) 
{
    if (IsAvailable){
        throw 0;
    }
    if (kilometers < Kilometers){
        throw 1;
    }

    double cost = PricePerKM * (kilometers - Kilometers);
    Kilometers = kilometers;
    IsAvailable = true;
    return cost;
}

string Car::ToString() const
{
    return Manufacturer + " - " + Model + ", " + LicensePlate;
}

string Car::GetManufacturer() const
{
    return Manufacturer;
}

string Car::GetModel() const
{
    return Model;
}

int Car::GetBuildYear() const
{
    return BuildYear;
}

string Car::GetLicensePlate() const
{
    return LicensePlate;
}

bool Car::GetNeedsCleaning() const
{
    return NeedsCleaning;
}

int Car::GetKilometers() const
{
    return Kilometers;
}

bool Car::GetIsAvailable() const
{
    return IsAvailable;
}

double Car::GetPricePerKM() const
{
    return PricePerKM;
}



Car::Car(std::string manufacturer, std::string model, int buildyear, std::string licenseplate, double pricePerKM) 
{
    Kilometers = 0;
    IsAvailable = true;
    NeedsCleaning = false;

    Manufacturer = manufacturer;
    BuildYear = buildyear;
    LicensePlate = licenseplate;
    Model = model;
    PricePerKM = pricePerKM;
}
