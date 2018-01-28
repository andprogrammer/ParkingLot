#include "Utils.h"
#include "ParkingControler.h"
#include "Interactive.h"
#include "FileContent.h"

using namespace std;


string convertColorToString(const Color &color)    //possible static_cast<int>(color)
{
    switch(color)
    {
        case Color::WHITE:
            return "White";
        case Color::BLACK:
            return "Black";
        case Color::RED:
            return "Red";
        case Color::BLUE:
            return "Blue";
    }
    return "";
}

Color convertStringToColor(const string &input)
{
    if(input == "White") return Color::WHITE;
    else if(input == "Black") return Color::BLACK;
    else if(input == "Red") return Color::RED;
    else if(input == "Blue") return Color::BLUE;
    return Color::UNDEFINED;
}

void handleArgumentData(int argc, char** argv)
{
    if(argc == 1) ParkingLot::ParkingControler::instance(make_unique<ParkingLot::Interactive>()).execute();
    else if(argc == 2)
    {
        if(!argv) return;
        ParkingLot::ParkingControler::instance(make_unique<ParkingLot::FileContent>(string(argv[1]))).execute();
    }
}
