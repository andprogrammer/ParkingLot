#ifndef PARKING_CONTROLER_H
#define PARKING_CONTROLER_H
#include "LibsAndClassDeclarations.h"
#include "ReaderStrategy.h"


namespace ParkingLot
{
    class ParkingControler
    {
        ParkingControler(std::unique_ptr<ReaderStrategy> &&strategy);
        ParkingControler(const ParkingControler&) = delete;
        ParkingControler(ParkingControler&&) = delete;
        ParkingControler& operator=(const ParkingControler&) = delete;
        ParkingControler& operator=(ParkingControler&&) = delete;
        ~ParkingControler() = default;

        std::unique_ptr<ReaderStrategy> strategy;

    public:
        static ParkingControler& instance(std::unique_ptr<ReaderStrategy> &&strategy)
        {
            static ParkingControler parkingControler(move(strategy));
            return parkingControler;
        }

        void execute() const;
    };
}

#endif  //PARKING_CONTROLER_H
