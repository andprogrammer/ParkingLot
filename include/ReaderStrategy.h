#ifndef READER_STRATEGY_H
#define READER_STRATEGY_H
#include "LibsAndClassDeclarations.h"
#include "Parking.h"


namespace ParkingLot
{
    class ReaderStrategy
    {
    protected:
        std::unique_ptr<Parking> parking;

    public:
        virtual ~ReaderStrategy() {}

        virtual void parse() = 0;
        void handleOperation(const std::string &line);
    };
}

#endif  //READER_STRATEGY_H
