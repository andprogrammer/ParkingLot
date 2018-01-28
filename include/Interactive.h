#ifndef INTERACTIVE_H
#define INTERACTIVE_H
#include "LibsAndClassDeclarations.h"
#include "ReaderStrategy.h"


namespace ParkingLot
{
    class Interactive : public ReaderStrategy
    {
    public:
        void parse() override;
    };
}

#endif  //INTERACTIVE_H
