#include "Tests.h"
#include "LibsAndClassDeclarations.h"
#include "Car.h"
#include "Parking.h"
#include "ParkingControler.h"
#include "Interactive.h"
#include "FileContent.h"

using namespace std;
using namespace ParkingLot;


namespace ParkingLotUnitTests
{
    void generalTests() //example input from pdf
    {
        ParkingLot::Car c1(Color::WHITE, "​KA-01-HH-1234");
        ParkingLot::Car c2(Color::WHITE, "​KA-01-HH-9999");
        ParkingLot::Car c3(Color::BLACK, "KA-01-BB-0001");
        ParkingLot::Car c4(Color::RED,   "​KA-01-HH-7777");
        ParkingLot::Car c5(Color::BLUE,  "KA-01-HH-2701");
        ParkingLot::Car c6(Color::BLACK, "KA-01-HH-3141");

        ParkingLot::Parking p(6);
        p.park(c1);
        p.park(c2);
        p.park(c3);
        p.park(c4);
        p.park(c5);
        p.park(c6);

        p.leave(4);

        p.status();

        ParkingLot::Car cRand1(Color::WHITE, "KA-01-P-333");
        ParkingLot::Car cRand2(Color::WHITE, "​DL-12-AA-9999");
        p.park(cRand1);
        p.park(cRand2);

        p.getRegistrationNumbersForCarsWithColour(Color::WHITE);

        p.getSlotNumberForCarsWithColor(Color::WHITE);

        p.getSlotNumberForRegistrationNumber("KA-01-HH-3141");
        p.getSlotNumberForRegistrationNumber("MH-04-AY-1111");
    }

    void carTest()
    {
        Color carColor = Color::WHITE;
        string registrationNumber = "KA-01-HH-7777";
        ParkingLot::Car c1(Color::WHITE, registrationNumber);
        cout << boolalpha;
        cout << (c1.getColor() == carColor) << endl;
        cout << (c1.getRegistrationNumber() == registrationNumber) << endl;
    }

    void fileContentTest()
    {
        ParkingLot::FileContent fc("file_inputs.txt");
        fc.parse();
    }

    void interactiveTest()
    {
        ParkingLot::Interactive i;
    }

    class ParkingHelper : public ParkingLot::Parking
    {
    public:
        ParkingHelper(uint32_t numberOfParkingSpaces) : ParkingLot::Parking(numberOfParkingSpaces)
        {}

        vector<ParkingLot::Car*> getCarContainer() { return carContainer; }
    };

    void parkingTest()
    {
        string registrationNumber1 = "​KA-01-HH-1234";
        string registrationNumber2 = "​KA-01-HH-9999";
        string registrationNumber3 = "KA-01-BB-0001";
        string registrationNumber4 = "​KA-01-HH-7777";
        string registrationNumber5 = "KA-01-HH-2701";
        string registrationNumber6 = "KA-01-HH-3141";
        ParkingLot::Car c1(Color::WHITE, registrationNumber1);
        ParkingLot::Car c2(Color::WHITE, registrationNumber2);
        ParkingLot::Car c3(Color::BLACK, registrationNumber3);
        ParkingLot::Car c4(Color::RED,   registrationNumber4);
        ParkingLot::Car c5(Color::BLUE,  registrationNumber5);
        ParkingLot::Car c6(Color::BLACK, registrationNumber6);

        uint32_t numberOfParkingSpaces = 6u;
        ParkingHelper ph(numberOfParkingSpaces);
        cout << (ph.getCarContainer().size() == numberOfParkingSpaces) << endl;
        for(const auto &car : ph.getCarContainer()) cout << (car == nullptr) << endl;

        ph.park(c1);
        ph.park(c2);
        ph.park(c3);
        ph.park(c4);
        ph.park(c5);
        ph.park(c6);
        for(const auto &car : ph.getCarContainer()) cout << (car != nullptr) << endl;
        cout << (ph.getCarContainer()[0]->getColor() == Color::WHITE) << " " << (ph.getCarContainer()[0]->getRegistrationNumber() == registrationNumber1) << endl;
        cout << (ph.getCarContainer()[1]->getColor() == Color::WHITE) << " " << (ph.getCarContainer()[1]->getRegistrationNumber() == registrationNumber2) << endl;
        cout << (ph.getCarContainer()[2]->getColor() == Color::BLACK) << " " << (ph.getCarContainer()[2]->getRegistrationNumber() == registrationNumber3) << endl;
        cout << (ph.getCarContainer()[3]->getColor() == Color::RED) << " " << (ph.getCarContainer()[3]->getRegistrationNumber() == registrationNumber4) << endl;
        cout << (ph.getCarContainer()[4]->getColor() == Color::BLUE) << " " << (ph.getCarContainer()[4]->getRegistrationNumber() == registrationNumber5) << endl;
        cout << (ph.getCarContainer()[5]->getColor() == Color::BLACK) << " " << (ph.getCarContainer()[5]->getRegistrationNumber() == registrationNumber6) << endl;

        ph.leave(4);
        cout << (ph.getCarContainer()[3] == nullptr) << endl;

        //    ph.status();

        string carRandRegistrationNumber1 = "KA-01-P-333";
        string carRandRegistrationNumber2 = "​DL-12-AA-999";
        ParkingLot::Car carRand1(Color::WHITE, carRandRegistrationNumber1);
        ParkingLot::Car carRand2(Color::WHITE, carRandRegistrationNumber2);
        ph.park(carRand1);
        ph.park(carRand2);
        cout << (ph.getCarContainer()[3]->getColor() == Color::WHITE) << " " << (ph.getCarContainer()[3]->getRegistrationNumber() == carRandRegistrationNumber1) << endl;
        for(const auto &car : ph.getCarContainer())
            cout << (car->getRegistrationNumber() != carRandRegistrationNumber2) << " ";
        cout << endl;

        //    p.getRegistrationNumbersForCarsWithColour(Color::WHITE);

        //    p.getSlotNumberForCarsWithColor(Color::WHITE);

        //    p.getSlotNumberForRegistrationNumber("KA-01-HH-3141");
        //    p.getSlotNumberForRegistrationNumber("MH-04-AY-1111");
    }

    void utilsTest()
    {
        cout << (convertColorToString(Color::WHITE) == "White") << endl;
        cout << (convertColorToString(Color::UNDEFINED) == "") << endl;

        cout << (convertStringToColor("White") == Color::WHITE) << endl;
        cout << (convertStringToColor("Undefined") == Color::UNDEFINED) << endl;
    }

    void runUnitTests()
    {
        cout << boolalpha;

        generalTests();
        carTest();
        fileContentTest();
        interactiveTest();
        parkingTest();
        utilsTest();
    }
}   //ParkingLotUnitTests
