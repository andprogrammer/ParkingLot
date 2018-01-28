#include "ReaderStrategy.h"

using namespace std;


namespace ParkingLot
{
    void ReaderStrategy::handleOperation(const string &line)
    {
        istringstream iss(line);
        string command = "";
        iss >> command;

        if((command == "create_parking_lot") && parking == nullptr)
        {
            int numberOfLots = 0;
            iss >> numberOfLots;
            parking = make_unique<Parking>(numberOfLots);
        }
        else if((command == "park") && parking)
        {
            string registrationNumber = "";
            string color = "";
            iss >> registrationNumber;
            iss >> color;
            Car c(convertStringToColor(color), registrationNumber);
            parking->park(c);
        }
        else if((command == "leave") && parking)
        {
            int position = 0;
            iss >> position;
            parking->leave(position);
        }
        else if((command == "status") && parking)
        {
            parking->status();
        }
        else if((command == "registration_numbers_for_cars_with_colour") && parking)
        {
            string color = "";
            iss >> color;
            parking->getRegistrationNumbersForCarsWithColour(convertStringToColor(color));
        }
        else if((command == "slot_numbers_for_cars_with_colour") && parking)
        {
            string color = "";
            iss >> color;
            parking->getSlotNumberForCarsWithColor(convertStringToColor(color));
        }
        else if((command == "slot_number_for_registration_number") && parking)
        {
            string registrationNumber = "";
            iss >> registrationNumber;
            parking->getSlotNumberForRegistrationNumber(registrationNumber);
        }
    }
}
