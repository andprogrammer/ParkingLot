#include "FileContent.h"

using namespace std;


namespace ParkingLot
{
    FileContent::FileContent(const string &fileName) : ReaderStrategy(), fileStream(fileName)
    {}

    FileContent::~FileContent()
    {
        if(fileStream.is_open()) fileStream.close();
    }

    void FileContent::parse()
    {
        if(fileStream.is_open())
        {
            string line = "";
            while(getline(fileStream, line))
            {
                handleOperation(line);
            }
        }
    }
}
