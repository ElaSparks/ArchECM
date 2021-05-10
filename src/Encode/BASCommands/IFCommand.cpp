#include "../../../include/ArithmeticLogicUnit.h"
std::string
ArithmeticLogicUnit::commandIF(const std::string& line, int& startAt)
{
    char letter = line[line.find("IF ") + 3];
    int letterAddr = letterAddress(letter);
    if (letterAddr == -1)
        return std::string{};
    std::string type;
    if (line.find(" == ") != -1)
        type = " JZ ";
    else if (line.find(" < ") != -1)
        type = " JNEG ";
    else
        return std::string{};
    std::stringstream ss(line.substr(line.find("GOTO ") + 5));
    int address;
    ss >> address;
    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << " LOAD " << letterAddr << "\n";
    result << std::setw(2) << std::setfill('0') << startAt++;
    result << type << "?" << address << "\n";
    return result.str();
}