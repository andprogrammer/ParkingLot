#ifndef UTILS_H
#define UTILS_H
#include "LibsAndClassDeclarations.h"


enum class Color : std::uint16_t
{
    WHITE, BLACK, RED, BLUE, UNDEFINED
};

std::string convertColorToString(const Color &color);
Color convertStringToColor(const std::string &input);
void handleArgumentData(int argc, char** argv);

#endif  //UTILS_H
