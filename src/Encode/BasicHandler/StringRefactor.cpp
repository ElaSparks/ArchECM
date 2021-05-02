#include "../../../include/ArithmeticLogicUnit.h"
void ArithmeticLogicUnit::replace(
        std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return;
    int startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
}

void ArithmeticLogicUnit::deleteAllSpaces(std::string& line)
{
    while (strchr(" ", line[0]))
        line.erase(line.begin(), line.begin() + 1);
}