#ifndef CAR_H
#define CAR_H
#include "LibsAndClassDeclarations.h"

namespace ParkingLot
{
    class Car
    {
    protected:
        Color c;
        std::string registrationNumber;

    public:
        Car(const Color &c, const std::string &registrationNumber);
        Car() = default;

        std::string getRegistrationNumber() const { return registrationNumber; }
        Color getColor() const { return c; }

        friend std::ostream& operator<<(std::ostream &o, const Car &c);
    };
}

#endif  //CAR_H
