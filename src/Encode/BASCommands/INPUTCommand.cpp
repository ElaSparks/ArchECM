#include "../../../include/ArithmeticLogicUnit.h"
std::string
ArithmeticLogicUnit::commandINPUT(const std::string& line, int& startAt)
{
    char letter = line[line.find("INPUT ") + 6];
    int address = letterAddress(letter);
    if (address == -1)
        return std::string{};
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " READ " << address << "\n";
    return result.str();
}