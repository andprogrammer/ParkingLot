#include "Interactive.h"

using namespace std;


namespace ParkingLot
{
    void Interactive::parse()
    {
        string line = "";
        while(getline(cin, line))
        {
            handleOperation(line);
        }
    }
}
