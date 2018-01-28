#ifndef FILE_CONTENT_H
#define FILE_CONTENT_H
#include "LibsAndClassDeclarations.h"
#include "ReaderStrategy.h"


namespace ParkingLot
{
    class FileContent : public ReaderStrategy
    {
        std::ifstream fileStream;

    public:
        FileContent(const std::string &fileName);
        virtual ~FileContent();

        void parse() override;
    };
}

#endif  //FILE_CONTENT_H
