#include "../../../include/ArithmeticLogicUnit.h"
/**
 * Broadcasting the OUTPUT Command. Converting into WRITE asm command.
 * @param line - a line of basic code. Added to the function to parse the
 * letter address
 * @param startAt - the line number with which the broadcast will begin
 * @return Broadcast result
 */
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