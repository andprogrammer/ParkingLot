#include "ParkingControler.h"

using namespace std;


namespace ParkingLot
{
    ParkingControler::ParkingControler(unique_ptr<ReaderStrategy> &&strategy) : strategy(move(strategy))
    {}

    void ParkingControler::execute() const
    {
        strategy->parse();
    }
}
