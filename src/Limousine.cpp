#include "Limousine.h"

// TODO: implement your class methods here


double Limousine::Return(int kilometers) 
{
    double price = Car::Return(kilometers);
    NeedsCleaning = true;
    return price;
}

bool Limousine::GetHasMinibar() const
{
    return HasMinibar;
}

void Limousine::Clean() 
{
    NeedsCleaning = false;
}

Limousine::Limousine(std::string manufacturer, std::string model, int buildyear, std::string licenseplate, bool hasMinibar) 
{
    Kilometers = 0;
    IsAvailable = true;
    NeedsCleaning = false;

    Manufacturer = manufacturer;
    BuildYear = buildyear;
    LicensePlate = licenseplate;
    Model = model;
    HasMinibar = hasMinibar;
}
