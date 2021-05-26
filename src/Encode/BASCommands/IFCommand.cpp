#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the IF Command. Converting into JZ and JNEG asm commands. The
 * address in temporarily presented in the format '?(address in basic)'
 * @param line - a line of basic code. Added to the function to parse the
 * address
 * @param startAt - the line number with which the broadcast will begin
 * @return Broadcast result
 */
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