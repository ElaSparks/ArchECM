#include "../../../include/ArithmeticLogicUnit.h"
std::string ArithmeticLogicUnit::commandEND(int& startAt)
{
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " HALT 00\n";
    return result.str();
}