#ifndef __SEDAN_H__
#define __SEDAN_H__

#include "Car.h"

class Sedan: Car{
    public:
        double PricePerKm =  0.29;
        bool HasTowbar;
        int LastCleanedAtKm;
        
        Sedan(std::string manufacturer, std::string model, int buildyear, std::string licenseplate, bool hasTowbar);

        bool GetHasTowbar() const;

        bool GetNeedsCleaning();

        void Clean();
};

#endif // __SEDAN_H__