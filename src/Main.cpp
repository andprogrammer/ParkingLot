/*
 * ParkingLot
 * g++ (Ubuntu 7.2.0-8ubuntu3) 7.2.0
 * Ubuntu 17.10
 * No Google Test/Mock
 */
#include "LibsAndClassDeclarations.h"

#define ENABLE_TESTS 0

using namespace std;


int main(int argc, char** argv)
{
    handleArgumentData(argc, argv);

#if ENABLE_TESTS
    ParkingLotUnitTests::runUnitTests();
#endif

    return 0;
}

/*
 * RUN:
 * clear && mkdir build && cd build && cmake .. && make && ./parking_lot file_inputs.txt
 */
