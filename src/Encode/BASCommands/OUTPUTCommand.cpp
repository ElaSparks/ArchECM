#include "../../../include/ArithmeticLogicUnit.h"
std::string
ArithmeticLogicUnit::commandOUTPUT(const std::string& line, int& startAt)
{
    char letter = line[line.find("OUTPUT ") + 7];
    int address = letterAddress(letter);
    if (address == -1)
        return std::string{};
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " WRITE " << address << "\n";
    return result.str();
}