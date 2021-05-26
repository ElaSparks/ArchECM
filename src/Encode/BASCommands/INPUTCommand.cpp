#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the INPUT Command. Converting into READ asm command.
 * @param line - a line of basic code. Added to the function to parse the
 * letter address
 * @param startAt - the line number with which the broadcast will begin
 * @return Broadcast result
 */
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