#include <string>

#ifndef __CAR_H__
#define __CAR_H__

class Car{
    protected:
        int Kilometers;
        std::string Manufacturer;
        std::string Model;
        int BuildYear;
        std::string LicensePlate;
        bool NeedsCleaning;
        bool IsAvailable;
        double PricePerKM;

    public: 
        Car() = default;
        Car(std::string manufacturer, std::string model, int buildyear, std::string licenseplate, double pricePerKM);

        bool Rent();
        virtual double Return(int kilometers);
        virtual void Clean(); //abstract in C#

        std::string ToString() const;

        std::string GetManufacturer() const;
        std::string GetModel() const;
        int GetBuildYear() const;
        std::string GetLicensePlate() const;
        bool GetNeedsCleaning() const;
        int GetKilometers() const;
        bool GetIsAvailable() const;
        double GetPricePerKM() const;
};
#endif // __CAR_H__