#include "../../../include/ArithmeticLogicUnit.h"
std::string ArithmeticLogicUnit::commandIF(
        const std::string& line,
        int& startAt,
        std::vector<int> compare,
        int rems)
{
    char letter = line[line.find("IF ") + 3];
    int letterAddr = letterAddress(letter);
    if (letterAddr == -1)
        return std::string{};
    std::string type;
    if (line.find(" == "))
        type = " JZ ";
    else if (line.find(" < "))
        type = " JNEG ";
    else
        return std::string{};
    std::stringstream ss(line.substr(line.find("GOTO ") + 5));
    int address;
    ss >> address;
    if (address / 10 - rems < 1 || address / 10 - rems > compare.size()) {
        return std::string{};
    }
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " LOAD " << letterAddr << "\n";
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << type << compare[address / 10 - 1 - rems] << "\n";
    return result.str();
}