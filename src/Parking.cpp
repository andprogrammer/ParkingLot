#include "Parking.h"
#include "Utils.h"

using namespace std;


namespace ParkingLot
{
    Parking::Parking(uint32_t numberOfParkingSpaces)
    {
        carContainer.reserve(numberOfParkingSpaces);
        for(uint32_t i=0u; i<numberOfParkingSpaces; ++i)
        {
            carContainer.push_back(nullptr);
        }
        cout << "Created​ ​a parking​ lot​ with " << numberOfParkingSpaces << " slots" << endl;
    }

    void Parking::park(const Car& c)
    {
        bool freeParkingSpaceFounded = false;
        int counter = 0;
        for(auto &car : carContainer)
        {
            ++counter;
            if(car == nullptr)
            {
                freeParkingSpaceFounded = true;
                car = new Car(c);
                cout << "Allocated​ ​ slot​ ​ number:​  " << counter << endl;
                return;
            }
        }
        if(!freeParkingSpaceFounded) cout << "Sorry,​ ​ parking​ ​ lot​ ​ is​ ​ full" << endl;
    }

    void Parking::leave(int position)
    {
        if(position >= carContainer.size() || position < 0) return;
        if(position > 0) --position;    //e.g. leave 4 which is on 3th position in container
        delete carContainer[position];
        carContainer[position] = nullptr;
        cout << "Slot​ ​ number​ ​ " << ++position << " ​ ​ is​ ​ free" << endl;    //print input position
    }

    void Parking::status() const
    {
        cout << "Slot​ ​ No. Registration​ ​ No Colour" << endl;
        int counter = 0;
        for(const auto &car : carContainer)
        {
            ++counter;
            if(car != nullptr)
            {
                cout << counter << "     " << car->getRegistrationNumber() << "     " << convertColorToString(car->getColor()) << endl;
            }
        }
    }

    void Parking::getRegistrationNumbersForCarsWithColour(const Color &c) const
    {
        bool firstInstance = true;
        for(const auto &car : carContainer)
        {
            if(car && car->getColor() == c)
            {
                if(firstInstance) firstInstance = false;
                else cout << ", ";
                cout << car->getRegistrationNumber();
            }
        }
        if(firstInstance) cout << "Not found";
        cout << endl;
    }

    void Parking::getSlotNumberForCarsWithColor(const Color &c) const
    {
        unsigned int slotCounter = 0;
        bool firstInstance = true;
        for(const auto &car : carContainer)
        {
            ++slotCounter;
            if(car && car->getColor() == c)
            {
                if(firstInstance) firstInstance = false;
                else cout << ", ";
                cout << slotCounter;
            }
        }
        if(firstInstance) cout << "Not found";
        cout << endl;
    }

    void Parking::getSlotNumberForRegistrationNumber(const string &registrationNumber) const
    {
        unsigned int slotCounter = 0;
        for(const auto &car : carContainer)
        {
            ++slotCounter;
            if(car && car->getRegistrationNumber() == registrationNumber)
            {
                cout << slotCounter << endl;
                return;
            }
        }
        cout << "Not found" << endl;
    }

    ostream& operator<<(ostream &o, const Parking &parking)
    {
        for(const auto& car : parking.carContainer)
            o << car << endl;
        return o;
    }
}
