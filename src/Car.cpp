#include "Car.h"

using namespace std;


namespace ParkingLot
{
    Car::Car(const Color &c, const string &registrationNumber) : c(c), registrationNumber(registrationNumber)
    {}

    ostream& operator<<(ostream &o, const Car &c)
    {
        o << "registration number=" << c.registrationNumber << " color=" << convertColorToString(c.getColor()) << endl;
        return o;
    }
}
