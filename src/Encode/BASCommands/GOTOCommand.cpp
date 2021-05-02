#include "../../../include/ArithmeticLogicUnit.h"
std::string ArithmeticLogicUnit::commandGOTO(
        const std::string& line,
        int& startAt,
        std::vector<int> compare,
        int rems)
{
    std::stringstream ss(line.substr(line.find("GOTO ") + 5));
    int address;
    ss >> address;
    if (address / 10 - rems < 1 || address / 10 - rems > compare.size())
        return std::string{};
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " JUMP " << compare[address / 10 - 1 - rems] << "\n";
    return result.str();
}