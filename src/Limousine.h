#include <string>

#ifndef __LIMOUSINE_H__
#define __LIMOUSINE_H__

#include "Car.h"

class Limousine: Car{
    public:
        double PricePerKm = 2.5;
        bool HasMinibar;

        Limousine(std::string manufacturer, std::string model, int buildyear, std::string licenseplate, bool hasMinibar);

        bool GetHasMinibar() const;

        void Clean();
};
#endif // __LIMOUSINE_H__