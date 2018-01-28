#ifndef PARKING_H
#define PARKING_H
#include "LibsAndClassDeclarations.h"
#include "Car.h"


namespace ParkingLot
{
    class Parking
    {
    protected:
        std::vector<Car*> carContainer;

    public:
        Parking(std::uint32_t numberOfParkingSpaces);

        void park(const Car& c);
        void leave(int position);
        void status(void) const;
        void getRegistrationNumbersForCarsWithColour(const Color &c) const;
        void getSlotNumberForCarsWithColor(const Color &c) const;
        void getSlotNumberForRegistrationNumber(const std::string &registrationNumber) const;

        friend std::ostream& operator<<(std::ostream &o, const Parking &parking);
    };
}

#endif  //PARKING_H
