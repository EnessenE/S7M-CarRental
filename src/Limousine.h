#ifndef __LIMOUSINE_H__
#define __LIMOUSINE_H__

#include <string>
#include "Car.h"

class Limousine: public Car{
    private:
        double PricePerKm = 2.5;
        bool HasMinibar;
    public:
        Limousine(std::string manufacturer, std::string model, int buildyear, std::string licenseplate, bool hasMinibar);

        bool GetHasMinibar() const;

        void Clean();

        double Return(int kilometers);
};
#endif // __LIMOUSINE_H__