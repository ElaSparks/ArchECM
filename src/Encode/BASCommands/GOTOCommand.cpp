#include "../../../include/ArithmeticLogicUnit.h"
std::string
ArithmeticLogicUnit::commandGOTO(const std::string& line, int& startAt)
{
    std::stringstream ss(line.substr(line.find("GOTO ") + 5));
    int address;
    ss >> address;
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " JUMP ?" << address << "\n";
    return result.str();
}