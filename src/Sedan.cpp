#include "Sedan.h" 

bool Sedan::GetHasTowbar() const
{
    return HasTowbar;
}

bool Sedan::GetNeedsCleaning() 
{
    return (Kilometers - LastCleanedAtKm) >= 1000;
}

void Sedan::Clean() 
{
    LastCleanedAtKm = Kilometers;
}

Sedan::Sedan(std::string manufacturer, std::string model, int buildyear, std::string licenseplate, bool hasTowbar) 
{
    PricePerKM = 0.29;
    Kilometers = 0;
    IsAvailable = true;
    NeedsCleaning = false;

    Manufacturer = manufacturer;
    BuildYear = buildyear;
    LicensePlate = licenseplate;
    Model = model;
    HasTowbar = hasTowbar;
}
